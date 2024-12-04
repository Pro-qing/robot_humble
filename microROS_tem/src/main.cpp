#include <Arduino.h>
#include <micro_ros_platformio.h>
#include <rcl/rcl.h>
#include <rclc/rclc.h>
# include <rclc/executor.h>
# include <std_msgs/msg/float32.h>
// # include <std_msgs/msg/string.h>
#include <Adafruit_NeoPixel.h>

rclc_executor_t executor;//创建执行器
rclc_support_t support;//创建支持对象
rcl_allocator_t allocator;//创建分配器
rcl_node_t node;//创建节点

//声明话题订阅者
rcl_subscription_t subscriber;
//声明话题发布者
rcl_publisher_t publisher;
//声明话题数据类型
std_msgs__msg__Float32 sub_msg;
std_msgs__msg__Float32 pub_msg;

//外设定义


//双核操作

void Sub_Task(void *pvParameters)
{
  
  while(1)
  {
    
  }
}

void Pub_Task(void *pvParameters)
{
  while(1)
  {
    
  }
}

//定义回调函数
void sub_callback(const void *msgin) {
  //将接收到的数据赋值给sub_msg
  const std_msgs__msg__Float32 * msg = (const std_msgs__msg__Float32 *)msgin;
  int value = msg->data;

  if (value == 1) {
    //code
  } else if (value == 0) {
    //code
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);// 设置波特率
  //设置串口进行microros通讯
  set_microros_serial_transports(Serial);
  // 等待连接
  delay(5000);
  // 初始化内存分配器
  allocator = rcl_get_default_allocator();
  //创建初始化选项
  rclc_support_init(&support, 0, NULL, &allocator);
  //创建节点
  rclc_node_init_default(&node, "micro_ros_node", "", &support);
  //发布者初始化
  rclc_publisher_init_default(
    &publisher, 
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Float32), 
    "led_state");
  //订阅者初始化
  rclc_subscription_init_default(
    &subscriber, 
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Float32), 
    "led_control");
  //创建执行器
  rclc_executor_init(&executor, &support.context, 2, &allocator);
  //为执行器添加订阅者
  rclc_executor_add_subscription(&executor, &subscriber, &sub_msg, &sub_callback, ON_NEW_DATA);

  //初始化外设

  //双核任务分配
  xTaskCreatePinnedToCore(
    Pub_Task, 
    "core0_main",
    4096,
    NULL,
    1, 
    NULL, 
    0);
  xTaskCreatePinnedToCore(
    Sub_Task, 
    "core1_main",
    4096,
    NULL,
    1, 
    NULL, 
    1);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);
  // 循环处理数据
  rclc_executor_spin_some(&executor, RCL_MS_TO_NS(100));
}


