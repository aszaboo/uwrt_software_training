#indef CIRCLE_TURT1_HPP
#define CIRCLE_TURT1_HPP

#include <vector>
#include <string>
#include <cstdlib>

#include <rclcpp/rclcpp.hpp>

#include <software_training/visibility.h>
#include <turtlesim/topic/geometry_msgs/msg/Twist.hpp>


class circle_turt1: public rclcpp::Node { // this line of code creates the class spawn_turts
                                                // the pubic tells specifies that the members of the rclcpp::Node
                                                // are accesable as public members of the spawn_turts class
    
    public: RESET_TURTS_PUBLIC // name adds readability
    explicit circle_turt1(const rclcpp::NodeOptions &options) // constuctor for spawn_turts whuch is used to specify options for creating a node

    private:
    rclcpp::Client<turtlesim::topic::Spawn>::SharedPtr client; // this liks a rclcpp client to the turtlesim spawn service
    rclcpp::TimerBase::SharedPtr timer; //binds timer to timerbase

    std::vector<std::string> turtle1_veloctiy = {linear: {x_lin: 10, y_lin: 0 , z_lin: 0}, angular: {x_ang: 0.0, y_ang: 0.0, z_ang:1.8}}; //specifies names for turtle spawns

    SOFTWARE_TRAINING_LOCAL
    void circle();
    };


}
#endif
