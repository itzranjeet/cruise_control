#ifndef ALGORITHM_NODE_H
#define ALGORITHM_NODE_H
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

class AlgorithmNode : public rclcpp::Node
{
public:
    AlgorithmNode()
        : Node("AlgorithmNode")
    {
        this->declare_parameter<int>("CruiseSpeed", 60);

        algorithm_node_subscriber = this->create_subscription<cruise_control::msg::AddressBook>(
            StubNodeOutputMessageTopic, StubNodeOutputMessageQueueSize, std::bind(&AlgorithmNode::subscribe_current_velocity, this, _1));

        algorithm_node_publisher = this->create_publisher<cruise_control::msg::AddressBook>(
            AlgorithmNodeOutputMessageTopic, AlgorithmNodeOutputMessageQueueSize);

        timer_ = this->create_wall_timer(
            1000ms, std::bind(&AlgorithmNode::publish_desired_acceleration, this));
    }

    void publish_desired_acceleration();
    void subscribe_current_velocity(const cruise_control::msg::AddressBook::SharedPtr msg);

    Acceleration desired_acceleration = 0;
    Deviation error;
    Deviation preError;
    Constant integral;
    Constant derivative;
    Velocity current_velocity;
    Speed CruiseSpeed;

private:
    cruise_control::msg::AddressBook::SharedPtr msg;
    rclcpp::Subscription<cruise_control::msg::AddressBook>::SharedPtr algorithm_node_subscriber;
    rclcpp::Publisher<cruise_control::msg::AddressBook>::SharedPtr algorithm_node_publisher;
    rclcpp::TimerBase::SharedPtr timer_;
};

#endif // ALGORITHM_NODE_H
