# ROS 1

## 安装ROS:

```
wget http://fishros.com/install -O fishros && . fishros
```

## 创建工作空间：

```
mkdir -p ~/catkin_ws/src 
```

```
cd ~/catkin_ws/
```

```
catkin_init_workspace src
```

```
catkin_make
```

```
source devel/setup.bash
```

```
echo "source ~/catkin_ws/devel/setup.bash" >> ~/.bashrc 
```

```
source ~/.bashrc
```

## 创建功能包

```
cd ~/catkin_ws/src
```

```
catkin_create_pkg my_robot_package roscpp std_msgs
```

```
cd ~/catkin_ws 
```

```
catkin_make
```

```
source devel/setup.bash
```

