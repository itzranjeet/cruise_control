#include "cruise_control/stub_node.hpp"
#include "cruise_control/applied_acceleration.hpp"

void StubNode::Run()
{
    RegisterPublisher();
    RegisterSubscriber();
}

void StubNode::RegisterPublisher()
{
    stub_node_publisher = this->create_publisher<cruise_control::msg::AddressBook>(
        StubNodeOutputMessageTopic, StubNodeOutputMessageQueueSize);

    timer_ = this->create_wall_timer(
        1000ms, std::bind(&StubNode::publish_current_velocity, this));

}

void StubNode::RegisterSubscriber()
{
    stub_node_subscriber = this->create_subscription<cruise_control::msg::AddressBook>(
        AlgorithmNodeOutputMessageTopic, AlgorithmNodeOutputMessageQueueSize,
        std::bind(&StubNode::subscribe_desired_acceleration, this, _1));
}

void StubNode::subscribe_desired_acceleration(const cruise_control::msg::AddressBook::SharedPtr msg)
{
    desired_acceleration = msg->desired_acceleration;
}

void StubNode::publish_current_velocity()
{
    AppliedAcceleration object;
    object.UpdateAcceleration();
    applied_acceleration = object.AppliedAccelerationInMPH;
    previous_velocity = current_velocity;
    if (desired_acceleration < applied_acceleration)
    {
        current_velocity = current_velocity + (desired_acceleration * EngineEfficiency);
    }
    else
    {
        current_velocity = current_velocity + (applied_acceleration * (desired_acceleration * YawRate));
    }
    difference = (current_velocity - previous_velocity);
    positive_difference = fabs(difference);

    if (positive_difference > threshold)
    {
        std::cout << "You Just Experienced a Jerk" << std::endl;
    }
    auto message = cruise_control::msg::AddressBook();
    message.velocity = current_velocity;
    std::cout << "StubNode: Publishing Velocity:      " << current_velocity << std::endl;
    stub_node_publisher->publish(message);
}




