#indef CLEAR_TURT_HPP
#define CLEAR_TURT_HPP

#include <vector>
#include <string>
#include <cstdlib>
#include <memory>

#include <rclcpp/rclcpp.hpp>

#include <software_training/visibility.h>
#include <turtlesim/srv/teleport_absolute.hpp>


namespace composition {
    
class reset_turt: public rclcpp::Node { // this line of code creates the class reset_turts
                                                // the pubic tells specifies that the members of the rclcpp::Node
                                                // are accesable as public members of the clear_all_turtles class
    
    public: RESET_TURTS_PUBLIC // name adds readability
    explicit reset_turt(const rclcpp::NodeOptions &options) // constuctor for reset_turt whuch is used to specify options for creating a node

    private:
    rclcpp::Client<turtlesim::srv::TeleportAbsolute>::SharedPtr client; // this liks a rclcpp client to the turtlesim teleport_absolute service
    rclcpp::TimerBase::SharedPtr timer; //binds timer to timerbase

    std::vector<std::string> turtle_positions = {x: 25, y: 10 , theta: 0, name: "moving_turtle"};, //specifies names for turtle spawns
                                        

    SOFTWARE_TRAINING_LOCAL
    void reset();
    };


} // namespace composition
#endif

