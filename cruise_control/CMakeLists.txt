cmake_minimum_required(VERSION 3.5)
project(cruise_control)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)

include_directories(include)

set(msg_files
  "msg/AddressBook.msg"
)

rosidl_generate_interfaces(${PROJECT_NAME}
  ${msg_files}
)
ament_export_dependencies(rosidl_default_runtime)
find_package(rclcpp REQUIRED)

add_executable(stub_node src/stub_node.cpp src/applied_acceleration.cpp)
ament_target_dependencies(stub_node "rclcpp")
rosidl_target_interfaces(stub_node ${PROJECT_NAME} "rosidl_typesupport_cpp")

add_executable(algorithm_node src/algorithm_node_main.cpp src/algorithm_node.cpp )
ament_target_dependencies(algorithm_node "rclcpp")
rosidl_target_interfaces(algorithm_node ${PROJECT_NAME} "rosidl_typesupport_cpp")

install(TARGETS 
stub_node
algorithm_node
 DESTINATION lib/${PROJECT_NAME})

 install(DIRECTORY
    launch
    DESTINATION share/${PROJECT_NAME}/
)

ament_export_include_directories(include)
ament_export_libraries(${libraries})
ament_export_dependencies(${dependencies})
ament_package()