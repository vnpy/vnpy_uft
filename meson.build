project(
  'vnpy_uft',
  'cpp',
  version: '3.7.4.1004.2',
  license: 'MIT',
  meson_version: '>=1.7.0',
  default_options: [
    'buildtype=release',
    'cpp_std=c++17',
    'warning_level=2',
  ],
)

# 导入文件系统和Python模块
fs = import('fs')
py = import('python').find_installation(pure: false)
py_dep = py.dependency()

# 获取pybind11路径
python_cmd = host_machine.system() == 'windows' ? 'python' : 'python3'
pybind11_include_dir = run_command(python_cmd, '-c', 'import pybind11; print(pybind11.get_include())', check: true).stdout().strip()
message('使用pybind11路径: ' + pybind11_include_dir)

# 获取编译器信息
cpp = meson.get_compiler('cpp')
compiler_id = cpp.get_id()

# 输出构建目标系统信息
message('构建目标系统: ' + host_machine.system())

# 初始化变量
extra_cpp_args = []
extra_link_args = []

# 初始化库变量
HsFutuSystemInfo_lib = []
HSMdApi_lib = []
HSTradeApi_lib = []
infocertsdk_lib = []
ldptcpsdk_lib = []
smf_api_lib = []
t2sdk_lib = []

# 初始化其他编译选项
install_rpath_value = ''

# 设置Windows特定编译选项
if host_machine.system() == 'windows'
  # Windows编译器设置
  add_project_arguments('/MT', language : 'cpp')
  
  # 设置库目录
  lib_dir = meson.current_source_dir() / 'vnpy_uft/api/libs'
  api_dir = meson.current_source_dir() / 'vnpy_uft/api'
  
  # 设置include目录
  include_dirs = include_directories(
    'vnpy_uft/api/include',
    'vnpy_uft/api/vnuft',
    pybind11_include_dir,
  )
  
  # 定义CTP库
  HsFutuSystemInfo_lib = cpp.find_library('HsFutuSystemInfo', 
                                       dirs: [lib_dir, api_dir],
                                       required: true)
  HSMdApi_lib = cpp.find_library('HSMdApi', 
                                       dirs: [lib_dir, api_dir],
                                       required: true)
  HSTradeApi_lib = cpp.find_library('HSTradeApi', 
                                       dirs: [lib_dir, api_dir],
                                       required: true)
  t2sdk_lib = cpp.find_library('t2sdk', 
                                       dirs: [lib_dir, api_dir],
                                       required: true)

# 设置Linux特定编译选项
else  # Linux
  # Linux编译器设置
  extra_cpp_args = [
    '-std=c++17',
    '-O3',
    '-Wno-delete-incomplete',
    '-Wno-sign-compare',
  ]
  
  extra_link_args = [
    '-lstdc++',
    '-Wl,-rpath,$ORIGIN',  # 添加rpath设置，使库能在运行时找到同目录下的动态库
  ]
  
  # 设置库目录
  lib_dir = meson.current_source_dir() / 'vnpy_uft/api'
  
  # 设置include目录
  include_dirs = include_directories(
    'vnpy_uft/api/include',
    'vnpy_uft/api/vnuft',
    pybind11_include_dir,
  )
  
  # 定义CTP库
  HsFutuSystemInfo_lib = cpp.find_library('HsFutuSystemInfo', 
                                       dirs: [lib_dir],
                                       required: true)
  HSMdApi_lib = cpp.find_library('HSMdApi', 
                                       dirs: [lib_dir],
                                       required: true)
  HSTradeApi_lib = cpp.find_library('HSTradeApi', 
                                       dirs: [lib_dir],
                                       required: true)
  infocertsdk_lib = cpp.find_library('infocertsdk', 
                                       dirs: [lib_dir],
                                       required: true)
  ldptcpsdk_lib = cpp.find_library('ldptcpsdk', 
                                       dirs: [lib_dir],
                                       required: true)
  smf_api_lib = cpp.find_library('smf_api', 
                                       dirs: [lib_dir],
                                       required: true)
  t2sdk_lib = cpp.find_library('t2sdk', 
                                       dirs: [lib_dir],
                                       required: true)
endif

# 创建MD模块扩展
md_module = py.extension_module(
  'vnuftmd',
  sources: ['vnpy_uft/api/vnuft/vnuftmd/vnuftmd.cpp'],
  include_directories: include_dirs,
  dependencies: [
    py_dep,
    HsFutuSystemInfo_lib,
    HSMdApi_lib,
    t2sdk_lib,
    infocertsdk_lib,
    ldptcpsdk_lib,
    smf_api_lib
  ],
  cpp_args: extra_cpp_args,
  link_args: extra_link_args,
  install: true,
  subdir: 'vnpy_uft/api'
)

# 创建TD模块扩展
td_module = py.extension_module(
  'vnufttd',
  sources: ['vnpy_uft/api/vnuft/vnufttd/vnufttd.cpp'],
  include_directories: include_dirs,
  dependencies: [
    py_dep,
    HsFutuSystemInfo_lib,
    HSTradeApi_lib,
    t2sdk_lib,
    infocertsdk_lib,
    ldptcpsdk_lib,
    smf_api_lib
  ],
  cpp_args: extra_cpp_args,
  link_args: extra_link_args,
  install: true,
  subdir: 'vnpy_uft/api'
)

# 安装Python源代码
python_files = [
  ['vnpy_uft/__init__.py', 'vnpy_uft'],
  ['vnpy_uft/api/__init__.py', 'vnpy_uft/api'],
  ['vnpy_uft/api/uft_constant.py', 'vnpy_uft/api'],
  ['vnpy_uft/gateway/__init__.py', 'vnpy_uft/gateway'],
  ['vnpy_uft/gateway/uft_gateway.py', 'vnpy_uft/gateway'],
]

foreach file : python_files
  py.install_sources(
    [file[0]],
    pure: false,
    subdir: file[1]
  )
endforeach

# 安装API动态库文件
if host_machine.system() == 'windows'
  api_libs = [
    'vnpy_uft/api/HsFutuSystemInfo.dll',
    'vnpy_uft/api/HSMdApi.dll',
    'vnpy_uft/api/HSTradeApi.dll',
    'vnpy_uft/api/infocertsdk.dll',
    'vnpy_uft/api/ldptcpsdk.dll',
    'vnpy_uft/api/smf_api.dll',
    'vnpy_uft/api/t2sdk.dll',
  ]
  
  install_data(
    api_libs,
    install_dir: py.get_install_dir() / 'vnpy_uft/api'
  )
else  # Linux
  api_libs = [
    'vnpy_uft/api/libHsFutuSystemInfo.so',
    'vnpy_uft/api/libHSMdApi.so',
    'vnpy_uft/api/libHSTradeApi.so',
    'vnpy_uft/api/libinfocertsdk.so',
    'vnpy_uft/api/libldptcpsdk.so',
    'vnpy_uft/api/libsmf_api.so',
    'vnpy_uft/api/libt2sdk.so',
  ]
  
  install_data(
    api_libs,
    install_dir: py.get_install_dir() / 'vnpy_uft/api'
  )
endif
