//
// Created by yuong on 23-8-16.
//

#ifndef __VEHICLE_MODEL_H__
#define __VEHICLE_MODEL_H__

#include <iostream>
namespace lingxi {
namespace common {

struct SingleHelmCommand {
  double _speed;
  double _angel;
//  double _front_wheel_offset;
};

struct DoubleHelmCommand {
  double _front_wheel_speed;
  double _rear_wheel_speed;
  double _front_wheel_angel;
  double _rear_wheel_angel;

};

struct DiffWheelCommand {
  double _left_wheel_speed;
  double _right_wheel_speed;
};

struct FourMecanumCommand {
  double _front_left_wheel_speed;
  double _front_right_wheel_speed;
  double _rear_left_wheel_speed;
  double _rear_right_wheel_speed;
};

union VehicleCommand {
  SingleHelmCommand _single_helm;
  DoubleHelmCommand _double_helm;
  DiffWheelCommand _diff_wheel;
  FourMecanumCommand _four_mecanum;
};

} // namespace common
} // namespace lingxi

#endif
