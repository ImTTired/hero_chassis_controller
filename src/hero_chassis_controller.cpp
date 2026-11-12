#include "hero_chassis_controller/hero_chassis_controller.h"

#include <pluginlib/class_list_macros.hpp>

namespace hero_chassis_controller {

bool HeroChassisController::init(
    hardware_interface::EffortJointInterface* hardware,
    ros::NodeHandle& root_nh,
    ros::NodeHandle& controller_nh) {
  (void)root_nh;
  (void)controller_nh;

  try {
    front_left_joint_ = hardware->getHandle("left_front_wheel_joint");
    front_right_joint_ = hardware->getHandle("right_front_wheel_joint");
    back_left_joint_ = hardware->getHandle("left_back_wheel_joint");
    back_right_joint_ = hardware->getHandle("right_back_wheel_joint");
  } catch (const hardware_interface::HardwareInterfaceException& error) {
    ROS_ERROR_STREAM("Failed to get wheel joint: " << error.what());
    return false;
  }

  ROS_INFO("HeroChassisController initialized.");
  return true;
}

void HeroChassisController::starting(const ros::Time& time) {
  (void)time;
}

void HeroChassisController::update(
    const ros::Time& time, const ros::Duration& period) {
  (void)time;
  (void)period;

  // V0.1: Safe zero-torque output.
  front_left_joint_.setCommand(0.0);
  front_right_joint_.setCommand(0.0);
  back_left_joint_.setCommand(0.0);
  back_right_joint_.setCommand(0.0);
}

void HeroChassisController::stopping(const ros::Time& time) {
  (void)time;

  front_left_joint_.setCommand(0.0);
  front_right_joint_.setCommand(0.0);
  back_left_joint_.setCommand(0.0);
  back_right_joint_.setCommand(0.0);
}

}  // namespace hero_chassis_controller

PLUGINLIB_EXPORT_CLASS(
    hero_chassis_controller::HeroChassisController,
    controller_interface::ControllerBase)
