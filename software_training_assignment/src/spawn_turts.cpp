#include <spawn_turtles.hpp>

using namespace std::chrono_literals;

namespace compoisition {
spawn_turts::spawn_turts(const rclcpp::NodeOptions &options) : Node("spawn_turts", options) {
            //creating client
            client = this->create_client<turtlesim::srv::SPAWN>("/spawn");
            // create callback
            timer = this->create_wall_timer(2s, std::bind(&spawn_turts::spawn, this));
}

void spawn_turts::spawn() {

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

  for (std::string &name : turtle_positions) {
    auto request = std::make_shared<turtlesim::srv::Spawn::Request>();
    request->name = name; // requests the name of the turtle

    auto callback =
        [this](rclcpp::Client<turtlesim::srv::Spawn>::SharedFuture response)
        -> void {
      (void)response;
      RCLCPP_INFO(this->get_logger(), "Turtles Spawned");
      rclcpp::shutdown(); // need this or else will keep on executing callback -
                          // only want to execute once!
 };

    auto result = client->async_send_request(request, callback);
  }
}

} // namespace composition


#include <rclcpp_components/register_node_macro.hpp>

RCLCPP_COMPONENTS_REGISTER_NODE(composition::spawn_turts)
