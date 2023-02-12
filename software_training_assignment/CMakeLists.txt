cmake_minimum_required(VERSION 3.8)
project(software_training_assignment)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

# add_library(cmake_name SHARED src/main_code.cpp)

# target_compile_definitions(cmake_name PRIVATE "SOFTWARE_TRAINING_BUILDING_DLL")

# ament_target_dependencies(cmake_name
#   "rclcpp"
#   "rclcpp_components"
#   "turtlesim"
#   "std_msgs")   

# rosidl_target_interfaces(cmake_name ${PROJECT_NAME} "rosidl_typesupport_cpp") # need for custom srv

# # register name has to match up with cpp class name
# rclcpp_components_register_nodes(cmake_name "composition::class_name")
# set(node_plugins "${node_plugins}composition::class_name;$<TARGET_FILE:cmake_name\n>")


ament_package()