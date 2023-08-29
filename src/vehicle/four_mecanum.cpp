//
// Created by yuong on 23-8-18.
//

#include "four_mecanum.h"

ChassisMotionModel FourMecanum::InverseKinematic(double vx, double vy, double omega)
{
    double front_left_speed =
        (vx - vy - (_param._wheel_track / 2 + _param._wheel_base / 2) / 2 * omega) / _param._front_left_wheel_radius;
    double front_right_speed =
        (vx + vy + (_param._wheel_track / 2 + _param._wheel_base / 2) / 2 * omega) / _param._front_right_wheel_radius;
    double rear_left_speed =
        (vx + vy - (_param._wheel_track / 2 + _param._wheel_base / 2) / 2 * omega) / _param._rear_left_wheel_radius;
    double rear_right_speed =
        (vx - vy + (_param._wheel_track / 2 + _param._wheel_base / 2) / 2 * omega) / _param._rear_right_wheel_radius;

    _chassis_command._four_mecanum._front_left_wheel_speed = front_left_speed;
    _chassis_command._four_mecanum._front_right_wheel_speed = front_right_speed;
    _chassis_command._four_mecanum._rear_left_wheel_speed = rear_left_speed;
    _chassis_command._four_mecanum._rear_right_wheel_speed = rear_right_speed;

    return _chassis_command;
}

VehicleVelocity FourMecanum::ForwardKinematic(const ChassisMotionModel& feedback)
{
    VehicleVelocity vehicleVelocity;

    double v1 = feedback._four_mecanum._front_left_wheel_speed * _param._front_left_wheel_radius;
    double v2 = feedback._four_mecanum._front_right_wheel_speed * _param._front_right_wheel_radius;
    double v3 = feedback._four_mecanum._rear_left_wheel_speed * _param._rear_left_wheel_radius;

    double omega = (v2 - v3) / (2 * (_param._wheel_base / 2 + _param._wheel_track / 2));
    double vx = (v1 + v2) / 2;
    double vy = (v3 + v1) / 2;
    vehicleVelocity = {vx, vy, omega};

    return vehicleVelocity;
}