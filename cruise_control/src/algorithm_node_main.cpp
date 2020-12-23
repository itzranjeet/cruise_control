#include "cruise_control/algorithm_node.hpp"

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<AlgorithmNode>());
    rclcpp::shutdown();
    return 0;
}
