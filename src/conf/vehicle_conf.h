//
// Created by yuong on 23-8-28.
//

#ifndef KINEMATICS_VEHICLE_CONF_H
#define KINEMATICS_VEHICLE_CONF_H

#endif // KINEMATICS_VEHICLE_CONF_H
struct SingleHelmParam
{
  double _front_wheel_offset =0.2;
  double _wheel_radius = 0.3;
  double _gear_ratio;
  double _max_wheel_angle;
  double _min_wheel_angle;
  double _wheel_base = 2.0;
  double _wheel_track;
};

struct DoubleHelmParam
{
  double _front_wheel_offset;
  double _rear_wheel_offset;
  double _front_wheel_gear_ratio;
  double _rear_wheel_gear_ratio;
  double _front_wheel_radius;
  double _rear_wheel_radius;
  double _front_max_wheel_angle;
  double _front_min_wheel_angle;
  double _rear_max_wheel_angle;
  double _rear_min_wheel_angle;
  double _wheel_base;
  double _wheel_track;
};

struct DiffWheelParam
{
  double _left_wheel_radius;
  double _right_wheel_radius;
  double _wheel_track;
  double _left_wheel_gear_ratio;
  double _right_wheel_gear_ratio;
};

struct FourMecanumParam
{
  double _front_left_wheel_radius;
  double _front_right_wheel_radius;
  double _rear_left_wheel_radius;
  double _rear_right_wheel_radius;
  double _wheel_base;
  double _wheel_track;
};

union VehicleParam
{
  SingleHelmParam _single_steer_wheel;
  DoubleHelmParam _double_steer_wheel;
  DiffWheelParam _diff_wheel;
  FourMecanumParam _four_mecanum;
};

