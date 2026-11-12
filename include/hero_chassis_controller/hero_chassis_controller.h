#ifndef HERO_CHASSIS_CONTROLLER_HERO_CHASSIS_CONTROLLER_H_
#define HERO_CHASSIS_CONTROLLER_HERO_CHASSIS_CONTROLLER_H_

#include <controller_interface/controller.h>
#include <hardware_interface/joint_command_interface.h>
#include <ros/ros.h>

namespace hero_chassis_controller {

class HeroChassisController
    : public controller_interface::Controller<
          hardware_interface::EffortJointInterface> {
 public:
  bool init(hardware_interface::EffortJointInterface* hardware,
            ros::NodeHandle& root_nh,
            ros::NodeHandle& controller_nh) override;

  void starting(const ros::Time& time) override;

  void update(const ros::Time& time,
              const ros::Duration& period) override;

  void stopping(const ros::Time& time) override;

 private:
  hardware_interface::JointHandle front_left_joint_;
  hardware_interface::JointHandle front_right_joint_;
  hardware_interface::JointHandle back_left_joint_;
  hardware_interface::JointHandle back_right_joint_;
};

}  // namespace hero_chassis_controller

#endif  // HERO_CHASSIS_CONTROLLER_HERO_CHASSIS_CONTROLLER_H_
