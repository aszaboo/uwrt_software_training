#include "rclcpp/rclcpp.hpp"
#include <software_training_assignement/reset_turts.hpp>

namespace composition { //creating the node with options
    reset_turts::reset_turts(const rclcpp::NodeOptions &options) : Node("reset_turts", options) {
            //creating client
            client = this->create_client<turtlesim::srv::TeleportAbsolute>("/teleport_absolute");
            // create callback
            timer = this->create_wall_timer(2s, std::bind(&reset_turts::teleport_absolute, this));
}

void spawn_turts::reset() {

  // check if service exists
  if (!client->wait_for_service(2s)) { // says if there is no client wait 2s for the service
    if (!rclcpp::ok()) { // if the rclcpp status is not okay than return waiting...waiting...
      RCLCPP_ERROR(this->get_logger(),
                   "Waiting...Waiting...");
      return;
    }
    RCLCPP_INFO(this->get_logger(), "Service styll not available"); // returns message that the service is still not aval after waiting
    return;
  }

    auto request = std::make_shared<turtlesim::srv::Spawn::Request>(); //how does this know exactly what turtle to reset??
    request->x = reset_turts::turtle_positions::x
    request->y = reset_turts::turtle_positions::y
    request->theta = reset_turts::turtle_positions::theta

    auto callback =
        [this](rclcpp::Client<turtlesim::srv::TeleportAbsolute>::SharedFuture response)
        -> void {
      (void)response;
      RCLCPP_INFO(this->get_logger(), "Moving Turtle Reset");
      rclcpp::shutdown(); // need this or else will keep on executing callback -
                          // only want to execute once!
 };

    auto result = client->async_send_request(request, callback);
  }
}

} //composition

#include <rclcpp_components/register_node_macro.hpp>

RCLCPP_COMPONENTS_REGISTER_NODE(composition::reset_turts)