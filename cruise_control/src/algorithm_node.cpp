#include "cruise_control/algorithm_node.hpp"

void AlgorithmNode::subscribe_current_velocity(const cruise_control::msg::AddressBook::SharedPtr msg)
{
    current_velocity = msg->velocity;
    std::cout << "AlgorithmNode:Subscribing Velocity:      " << current_velocity << std::endl;
}

void AlgorithmNode::publish_desired_acceleration()
{
    this->get_parameter("CruiseSpeed", CruiseSpeed);

    error = CruiseSpeed - current_velocity;
    integral = integral + (error * dt);
    derivative = (error - preError) / dt;
    desired_acceleration = (Kp * error) + (Ki * integral) + (Kd * derivative);
    preError = error;

    auto message = cruise_control::msg::AddressBook();
    message.desired_acceleration = desired_acceleration;
    algorithm_node_publisher->publish(message);
}