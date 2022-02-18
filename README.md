# vn.py框架的恒生UFT接口

<p align="center">
  <img src ="https://vnpy.oss-cn-shanghai.aliyuncs.com/vnpy-logo.png"/>
</p>

<p align="center">
    <img src ="https://img.shields.io/badge/version-3.7.2.4.2-blueviolet.svg"/>
    <img src ="https://img.shields.io/badge/platform-windows|linux-yellow.svg"/>
    <img src ="https://img.shields.io/badge/python-3.7|3.8|3.9|3.10-blue.svg" />
    <img src ="https://img.shields.io/github/license/vnpy/vnpy.svg?color=orange"/>
</p>

## 说明

基于恒生极速API的3.7.2.4版本开发。

## 安装

安装需要基于3.0.0版本以上的[VN Studio](https://www.vnpy.com)。

直接使用pip命令：

```
pip install vnpy_uft
```

下载解压后在cmd中运行

```
pip install -e .
```

由于在安装的同时需要编译C++代码，因此在执行上述命令之前需要去微软[官网](https://my.visualstudio.com/Downloads?q=build%20tools)下载Visual Studio Build Tools。其中工作负荷选择Visual C++生成工具，同时推荐下载2017版。

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

期货：

{
    "用户名": "xxxxxx",
    "密码": "xxxxxx",
    "行情服务器": "101.71.12.144:9006",
    "交易服务器": "101.71.12.144:9006",
    "服务器类型": "期货",
    "产品名称": "Hs_JT_1.0",
    "授权编码": "20191127JTV1",
    "委托类型": "7"
}

ETF期权：

{
    "用户名": "xxxxxx",
    "密码": "xxxxxx",
    "行情服务器": "121.41.138.11:9869",
    "交易服务器": "121.41.138.11:9869",
    "服务器类型": "ETF期权",
    "产品名称": "",
    "授权编码": "",
    "委托类型": "7"
}
