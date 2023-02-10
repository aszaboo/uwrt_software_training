#ifndef CLEAR_TURTS_HPP
#define CLEAR_TURTS_HPP

#include <cstdlib>
#include <memory>
#include <string>
#include <vector>

#include <rclcpp/rclcpp.hpp>

#include <software_training/visibility.h>
#include <turtlesim/srv/kill.hpp>

namespace composition{

class clear_all_turtles : public rclcpp::Node { // this line of code creates the class clear_all_turtles
                                                // the pubic tells specifies that the members of the rclcpp::Node
                                                // are accesable as public members of the clear_all_turtles class
    
    public: CLEAR_TURTS_PUBLIC // name adds readability
    explicit clear_all_turtles(const rclcpp::NodeOptions &options) // constuctor for clr_all_turts whuch is used to specify options for creating a node

    private:
    rclcpp::Client<turtlesim::srv::Kill>::SharedPtr client;
    rclcpp::TimerBase::SharedPtr timer;

    // all the turtles
    std::vector<std::string> turtle_names = {"turtle1", "moving_turtle",
                                           "stationary_turtle"};
  SOFTWARE_TRAINING_LOCAL
  void kill_turtles();
};

} // namespace composition


#endif // CLEAR_TURTS_HPP