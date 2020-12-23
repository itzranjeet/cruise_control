from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
	Node(
            package='cruise_control',
            node_executable='algorithm_node',
            node_name='AlgorithmNode',
   	    output = 'screen',
	    emulate_tty=True,
            parameters=[
                {"CruiseSpeed": 60}]
        ),
        Node(
            package='cruise_control',
            node_executable='stub_node',
            node_name='StubNode',
	    output = 'screen',
        )
    ])

#ros2 launch cruise_control launch_cruise_control.py
#ros2 param set /AlgorithmNode CruiseSpeed 80

