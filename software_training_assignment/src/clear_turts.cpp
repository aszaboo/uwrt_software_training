#include <software_training/clear_turts.hpp>

using namespace std::chrono_literals;

namespace composition { //creating the node with options
    clear_turts::clear_turts(const rclcpp::NodeOptions &options) : Node("clear_turts", options) {
            //creating client
            client = this->create_client<turtlesim::srv::Kill>("/kill");
            // create callback
            timer = this->create_wall_timer(2s, std::bind(&clear_turts::kill, this));
}

void clear_turts::kill() {

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

  for (std::string &name : turtle_names) {
    auto request = std::make_shared<turtlesim::srv::Kill::Request>();
    request->name = name; // requests the name of the turtle

    auto callback =
        [this](rclcpp::Client<turtlesim::srv::Kill>::SharedFuture response)
        -> void {
      (void)response;
      RCLCPP_INFO(this->get_logger(), "Turtles Killed");
      rclcpp::shutdown(); // need this or else will keep on executing callback -
                          // only want to execute once!
 };

    auto result = client->async_send_request(request, callback);
  }
}

} // namespace composition

#include <rclcpp_components/register_node_macro.hpp>

RCLCPP_COMPONENTS_REGISTER_NODE(composition::clear_turts)

