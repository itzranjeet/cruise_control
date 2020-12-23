Rudimentary Cruise Control
==========================

### Introduction ###
Cruise control (sometimes known as speed control or auto cruise, or tempomat in some countries) is 
a system that automatically controls the speed of a motor vehicle. 
The system is a servomechanism that takes over the throttle of the car to maintain a steady speed as set by the driver.

### Problem Statement
Build a system of at least 2 ROS2 nodes that satisfy the following:

1. One node serves as sensor & actuator stub that reports vehicle velocity and updates it based on the input acceleration and configurable vehicle dynamics. Hereafter this is referred to as the stub node.

2. One node provides the algorithm for cruise control. It outputs the desired acceleration to be applied to the vehicle based on the current velocity that is input and configurable desired velocity. Hereafter this is referred to as the algorithm node.

3. The stub node and algorithm shall have complementary input and output configurations so they can be paired into a system that is complete. The system shall be extensible in terms of configurability and scalability. Some probable use-cases are listed below.

4. These nodes are implemented using ROS2.

5. They shall be deployed on one docker container or on two different containers. When they are on different containers/ machines they shall communicate using the virtual can bus interface.

6. For the stub node, minimally, the vehicle mass (or weight) shall be configured. Possibility to configure additional vehicle dynamics attributes are desired.

7. For the algorithm node, minimally, the desired speed (set value) shall be configurable. Possibility to configure additional cruise control parameters (such as maximum jerk) are desired.

8. The operation of the system shall be demonstrated by playing back a ROS Bag recorded during actual operation.


### Quick Start ###

**Docker**

* Download the Dockerfile from src/rudimentary_cruise_control/cruise_control/docker folder of cruise_controlV2.0 branch.
* Place it in a local folder and run the following commands.
* For Input download the Rosbag from src/rudimentary_cruise_control/cruise_control/data/Rosbag

```
sudo docker system prune
sudo docker build -t cruisecontrolimage .
sudo docker images
sudo docker run --name=cruisecontainer cruisecontrolimage

```
### References ###

1. [Cruise Control](https://en.wikipedia.org/wiki/Cruise_control/​)
2. [ROS2](https://index.ros.org/doc/ros2/​)
3. [ROS2 Tutorials](https://index.ros.org/doc/ros2/Tutorials/​)
4. [Docker](https://hub.docker.com/)