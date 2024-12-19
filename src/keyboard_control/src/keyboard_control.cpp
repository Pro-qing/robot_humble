#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "termios.h"
#include "unistd.h"

class KeyboardControlNode : public rclcpp::Node
{
public:
    KeyboardControlNode() : Node("keyboard_control_node")
    {
        publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(100), std::bind(&KeyboardControlNode::publish_velocity, this));
    }

private:
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    geometry_msgs::msg::Twist twist_;

    // 读取单个字符输入
    char getKey()
    {
        struct termios oldt, newt;
        char ch;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO); // 设置为非规范模式，不回显
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        return ch;
    }

    // 发布速度命令
    void publish_velocity()
    {
        char key = getKey();
        switch (key)
        {
            case 'w': // 前进
                twist_.linear.x = 0.5;
                twist_.angular.z = 0.0;
                break;
            case 's': // 后退
                twist_.linear.x = -0.5;
                twist_.angular.z = 0.0;
                break;
            case 'a': // 左转
                twist_.linear.x = 0.0;
                twist_.angular.z = 0.5;
                break;
            case 'd': // 右转
                twist_.linear.x = 0.0;
                twist_.angular.z = -0.5;
                break;
            case 'q': // 停止
                twist_.linear.x = 0.0;
                twist_.angular.z = 0.0;
                break;
            default:
                break;
        }
        publisher_->publish(twist_);
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<KeyboardControlNode>());
    rclcpp::shutdown();
    return 0;
}

