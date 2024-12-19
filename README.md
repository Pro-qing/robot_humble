# 功能包介绍目录

<!-- 

## model文件夹存放模型文件

1.树莓派底板

## move_base 功能包 ##

安装依赖:

创建功能包：

```
cd ~/jarvis_ws/src
ros2 pkg create --build-type ament_cmake move_base
```

节点名称：

话题名称：

节点功能：

## keyboard_control功能包

安装依赖

```
sudo apt install ros-humble-teleop-twist-keyboard
```

创建功能包：

```
cd ~/jarvis_ws/src
ros2 pkg create --build-type ament_cmake keyboard_control
```

节点名称：/keyboard_control_node

话题名称：/cmd_vel

节点功能：键盘控制小车行进（q停止w前进a左转s后退d右转）

消息格式：geometry_msgs/Twist

示例：

```
linear:
  x: 0.5
  y: 0.0
  z: 0.0
angular:
  x: 0.0
  y: 0.0
  z: 0.0
```

-->

