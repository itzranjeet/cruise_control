#ifndef STUB_NODE_H
#define STUB_NODE_H

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
//#include "cruise_control/ros.hpp"

using std::placeholders::_1;
using namespace std::chrono_literals;

class StubNode : public rclcpp::Node
{
public:
    StubNode()
        : Node("StubNode")
    {
        Run();
    }
    Velocity current_velocity;
    Velocity previous_velocity;
    Acceleration desired_acceleration;
    Deviation difference;
    Deviation positive_difference;
    Acceleration applied_acceleration;

    void subscribe_desired_acceleration(const cruise_control::msg::AddressBook::SharedPtr msg);
    void publish_current_velocity();
    void Run();
    void RegisterPublisher();
    void RegisterSubscriber();

private:
    cruise_control::msg::AddressBook::SharedPtr msg;
    rclcpp::Publisher<cruise_control::msg::AddressBook>::SharedPtr stub_node_publisher;
    rclcpp::Subscription<cruise_control::msg::AddressBook>::SharedPtr stub_node_subscriber;
    rclcpp::TimerBase::SharedPtr timer_;
};
#endif // STUB_NODE_H

#include "cruise_control/ros.hpp"

int main(int argc, char *argv[])
{
    //rclcpp::init(argc, argv);

    Ros object;
    object.init(argc, argv);
    //rclcpp::spin(std::make_shared<StubNode>());
    //object.spin();
    rclcpp::shutdown();
    return 0;
}
