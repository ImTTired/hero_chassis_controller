# hero_chassis_controller

RoboMaster Hero four-wheel mecanum chassis controller.

## Environment

- Ubuntu 20.04
- ROS Noetic
- Gazebo Classic 11
- Catkin Tools

## Development Status

### V0.1 - Controller Skeleton

- ROS Control plugin registration
- Four-wheel EffortJointInterface
- Safe zero-torque output

## Build

Run the following commands in Ubuntu 20.04:

    cd ~/rm_ws
    catkin build hero_chassis_controller -j2
    source ~/rm_ws/devel/setup.bash

## Planned Features

- Four independent velocity PID controllers
- Mecanum inverse kinematics
- Forward kinematics and odometry
- TF publishing
- Body-frame and world-frame velocity commands
