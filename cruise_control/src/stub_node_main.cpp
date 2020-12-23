#include "cruise_control/stub_node.hpp"
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