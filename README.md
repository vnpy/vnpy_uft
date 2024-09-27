# VeighNa框架的恒生UFT接口

<p align="center">
  <img src ="https://vnpy.oss-cn-shanghai.aliyuncs.com/vnpy-logo.png"/>
</p>

<p align="center">
    <img src ="https://img.shields.io/badge/version-3.7.4.1004-blueviolet.svg"/>
    <img src ="https://img.shields.io/badge/platform-windows|linux-yellow.svg"/>
    <img src ="https://img.shields.io/badge/python-3.10|3.11|3.12-blue.svg" />
    <img src ="https://img.shields.io/github/license/vnpy/vnpy.svg?color=orange"/>
</p>

## 说明

基于恒生极速API的3.7.4.1004版本开发。

## 安装

安装环境推荐基于3.9.0版本以上的【[**VeighNa Studio**](https://www.vnpy.com)】。

直接使用pip命令：

```
pip install vnpy_uft
```


或者下载源代码后，解压后在cmd中运行：

```
pip install .
```

使用源代码安装时需要进行C++编译，因此在执行上述命令之前请确保已经安装了【Visual Studio（Windows）】或者【GCC（Linux）】编译器。

## 使用

以脚本方式启动（script/run.py）：

```
from vnpy.event import EventEngine
from vnpy.trader.engine import MainEngine
from vnpy.trader.ui import MainWindow, create_qapp

from vnpy_uft import UftGateway


def main():
    """主入口函数"""
    qapp = create_qapp()

    event_engine = EventEngine()
    main_engine = MainEngine(event_engine)
    main_engine.add_gateway(UftGateway)
    
    main_window = MainWindow(main_engine, event_engine)
    main_window.showMaximized()

    qapp.exec()


if __name__ == "__main__":
    main()
```

## 连接

实盘交易时，请将期货公司提供的license.dat文件，放置于程序运行时目录（启动VeighNa Trader后，顶部标题栏所显示的目录）。

期货：

{
    "用户名": "xxxxxx",
    "密码": "xxxxxx",
    "行情服务器": "101.71.12.144:9006",
    "交易服务器": "101.71.12.144:9006",
    "产品名称": "Hs_JT_1.0",
    "授权编码": "20191127JTV1"
}

ETF期权：

{
    "用户名": "xxxxxx",
    "密码": "xxxxxx",
    "行情服务器": "101.71.12.149:8102",
    "交易服务器": "101.71.12.149:8102",
    "产品名称": "",
    "授权编码": ""
}
