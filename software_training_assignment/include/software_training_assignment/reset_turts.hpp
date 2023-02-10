#ifndef CLEAR_TURTLES_HPP
#define CLEAR_TURTLES_HPP

#include <cstdlib>
#include <memory>
#include <string>
#include <vector>

#include <rclcpp/rclcpp.hpp>

#include <software_training/visibility.h>
#include <turtlesim/srv/kill.hpp>

namespace clear_turtles {
    class clear_turtles : public rclcpp:Node { //this allows access to the rclcpp node package
    public:
        SOFTWARE_TRAINING_PUBLIC
        explicit clear_turtles(const rclcpp::NodeOptions &options);


    private:
    rclcpp::Client<turtlesim::srv::Kill>::SharedPtr client; // this liks a rclcpp client to the turtlesim kill service
    rclcpp::TimerBase::SharedPtr timer;

    std::vector<std::string> turtle_names = {"turtle1", "moving_turtle", //specifies which turtles to kill
                                           "stationary_turtle"};

        SOFTWARE_TRAINING_LOCAL
  void kill();
    };


}
#endif
