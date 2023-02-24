#indef CIRCLE_TURT_HPP
#define CIRCLE_TURT_HPP

#include <vector>
#include <string>
#include <cstdlib>

#include <rclcpp/rclcpp.hpp>

#include <software_training/visibility.h>
#include <turtlesim/topic/geometry_msgs/msg/Twist.hpp>


class circle_turt: public rclcpp::Node { // this line of code creates the class circle_turt
                                                // the pubic tells specifies that the members of the rclcpp::Node
                                                // are accesable as public members of the circle_turts class
    
    public: CIRCLE_TURT_PUB // name adds readability
    explicit circle_turt(const rclcpp::NodeOptions &options) // constuctor for circle_turts whuch is used to specify options for creating a node

    private:
    rclcpp::Client<turtlesim::topic::turtle1/cmd_vel>::SharedPtr client; // this links a rclcpp client to the turtlesim cmd_vel topic
    rclcpp::TimerBase::SharedPtr timer; //binds timer to timerbase

    std::vector<std::string> turtle_veloctiy = {linear: {x_lin: 10, y_lin: 0 , z_lin: 0}, angular: {x_ang: 0.0, y_ang: 0.0, z_ang:1.8}}; //specifies the velocity for turtle1

    SOFTWARE_TRAINING_LOCAL
    void circle();
    };


}
#endif
