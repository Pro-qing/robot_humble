# microROS

## 一，所需软件

​	vscode,platformio

## 二，所需硬件

​	esp32-s3,type-c数据线

## 三，下载注意事项

​	1，pio下载的时候，可能会遇到python环境无法识别，多次尝试后，依旧无法识别。

部分解决方案：禁用原先的python环境，在终端中输入

`sudo apt update`

`sudo apt install python3-venv`

然后等待下载即可。

## 四，Agent使用注意事项

​	端口需要固定

固定方法：

1.创建别名。

​	修改  xxx.rules文件即可。

2.其它方法自行查找验证。