import platform

from setuptools import Extension, setup


def get_ext_modules() -> list:
    """
    获取三方模块

    Linux和Windows需要编译封装接口
    Mac由于缺乏二进制库支持无法使用
    """
    if platform.system() == "Linux":
        extra_compile_flags = [
            "-std=c++17",
            "-O3",
            "-Wno-delete-incomplete",
            "-Wno-sign-compare",
        ]
        libraries = ["HsFutuSystemInfo", "HSMdApi", "HSTradeApi", "t2sdk", "tcpsdk"]
        extra_link_args = ["-lstdc++"]
        runtime_library_dirs = ["$ORIGIN"]
    else:
        libraries = ["HsFutuSystemInfo", "HSMdApi", "HSTradeApi", "t2sdk"]
        extra_compile_flags = ["-O2"]
        extra_link_args = []
        runtime_library_dirs = []

    vnuftmd = Extension(
        "vnpy_uft.api.vnuftmd",
        [
            "vnpy_uft/api/vnuft/vnuftmd/vnuftmd.cpp",
        ],
        include_dirs=["vnpy_uft/api/include",
                      "vnpy_uft/api/vnuft"],
        define_macros=[],
        undef_macros=[],
        library_dirs=["vnpy_uft/api/libs", "vnpy_uft/api"],
        libraries=libraries,
        extra_compile_args=extra_compile_flags,
        extra_link_args=extra_link_args,
        runtime_library_dirs=runtime_library_dirs,
        depends=[],
        language="cpp",
    )

    vnufttd = Extension(
        "vnpy_uft.api.vnufttd",
        [
            "vnpy_uft/api/vnuft/vnufttd/vnufttd.cpp",
        ],
        include_dirs=["vnpy_uft/api/include",
                      "vnpy_uft/api/vnuft"],
        define_macros=[],
        undef_macros=[],
        library_dirs=["vnpy_uft/api/libs", "vnpy_uft/api"],
        libraries=libraries,
        extra_compile_args=extra_compile_flags,
        extra_link_args=extra_link_args,
        runtime_library_dirs=runtime_library_dirs,
        depends=[],
        language="cpp",
    )

    return [vnufttd, vnuftmd]


setup(
    ext_modules=get_ext_modules(),
)
