import launch
import launch_ros.actions
from launch_ros.actions import ComposableNodeContainer
from launch_ros.descriptions import ComposableNode

def generate_launch_description():

    container = ComposableNodeContainer(
        name='software_training_container',
        namespace='',
        package='rclcpp_components',
        executable='component_container',
        composable_node_descriptions=[ComposableNode(
            package='software_training_assignment',
            plugin='composition::turtle_service_request_node',
            name='turtle_request'),
        ),
        ], 
        output='screen',

return launch.LaunchDescription([container])

def generate_launch_description():

    container = ComposableNodeContainer(
        name='software_training_container',
        namespace='',
        package='rclcpp_components',
        executable='component_container',
        composable_node_descriptions=[ComposableNode(
            package='software_training_assignment',
            plugin='composition::turtle_service_request_node',
            name='turtle_request'),
        ),
        ], 
        output='screen',
return launch.LaunchDescription([container])