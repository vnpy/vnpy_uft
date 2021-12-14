# vn.py框架的恒生UFT接口

<p align="center">
  <img src ="https://vnpy.oss-cn-shanghai.aliyuncs.com/vnpy-logo.png"/>
</p>

<p align="center">
    <img src ="https://img.shields.io/badge/version-3.7.1.16-blueviolet.svg"/>
    <img src ="https://img.shields.io/badge/platform-windows|linux-yellow.svg"/>
    <img src ="https://img.shields.io/badge/python-3.7-blue.svg" />
    <img src ="https://img.shields.io/github/license/vnpy/vnpy.svg?color=orange"/>
</p>

## 说明

基于恒生极速API的3.7.1.16版本开发。

## 安装

安装需要基于2.2.0版本以上的[VN Studio](https://www.vnpy.com)。

直接使用pip命令：

```
pip install vnpy_uft
```

下载解压后在cmd中运行

```
python setup.py install
```

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

连接前请先下载一个包含认证文件lisence.dat，放置在VN Trader运行目录（.vntrader同级文件夹）下。

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
