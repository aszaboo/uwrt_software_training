#indef SPAWN_TURTS_HPP
#define SPAWN_TURTS_HPP

#include <vector>
#include <string>
#include <cstdlib>

#include <rclcpp/rclcpp.hpp>

#include <software_training/visibility.h>
#include <turtlesim/srv/spawn.hpp>


class spawn_turts: public rclcpp::Node { // this line of code creates the class spawn_turts
                                                // the pubic tells specifies that the members of the rclcpp::Node
                                                // are accesable as public members of the spawn_turts class
    
    public: RESET_TURTS_PUBLIC // name adds readability
    explicit spawn_turts(const rclcpp::NodeOptions &options) // constuctor for spawn_turts whuch is used to specify options for creating a node

    private:
    rclcpp::Client<turtlesim::srv::Spawn>::SharedPtr client; // this liks a rclcpp client to the turtlesim spawn service
    rclcpp::TimerBase::SharedPtr timer; //binds timer to timerbase

    std::vector<std::string> turtle_positions = {{x: 25, y: 10 , theta: 0, name: "moving_turtle"}, //specifies names for turtle spawns
                                           {x: 5, y: 5 , theta: 0, name: "stationary_turtle"}};

    SOFTWARE_TRAINING_LOCAL
    void spawn();
    };


}
#endif
