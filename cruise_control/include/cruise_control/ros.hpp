#ifndef ROS_H
#define ROS_H

#include <chrono>
#include <memory>
#include <fstream>
#include <iostream>
#include <thread>
#include <math.h>
#include "rclcpp/rclcpp.hpp"
#include "cruise_control/msg/address_book.hpp"
#include "cruise_control/constants.hpp"
#include "datatypes/datatypes.hpp"

using std::placeholders::_1;
using namespace std::chrono_literals;

class Ros : public rclcpp::Node {

public:

    Ros() : Node("Ros")
    {
        RCLCPP_INFO(this->get_logger(), "Node created!!");
    }

    /*void add_publisher(const std::string &topic, uint32_t size)
    {
        _publisher = this->create_publisher<std_msgs::msg::String>(topic, size);
        std::cout<<"I am here"<<std::endl;
    }*/

    /*void init(int argc, char *argv[])
    {
        rclcpp::init(argc, argv);
        std::cout<<"I am in Init"<<std::endl;
    }

    void spin()
    {
        rclcpp::spin(std::make_shared<StubNode>());
        std::cout<<"I am in spin"<<std::endl;
    }*/



private:

    //rclcpp::Publisher<std_msgs::msg::String>::SharedPtr _publisher;

};
#endif //ROS_H