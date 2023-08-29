//
// Created by yuong on 23-8-18.
//

#include "diff_wheel.h"

ChassisMotionModel DiffWheel::InverseKinematic(double vx, double vy, double omega)
{
    double v = sqrt(vx * vx + vy * vy);
    double epsilon = 1.0e-6;
    if (omega < epsilon)
    {
        _chassis_command._diff_wheel._left_wheel_speed = v;
        _chassis_command._diff_wheel._right_wheel_speed = v;
        return _chassis_command;
    }
    double turning_radius = v / omega;
    double left_wheel_speed = omega * (turning_radius - _param._wheel_track / 2) / _param._left_wheel_radius;
    double right_wheel_speed = omega * (turning_radius + _param._wheel_track / 2) / _param._right_wheel_radius;

    _chassis_command._diff_wheel._left_wheel_speed = left_wheel_speed;
    _chassis_command._diff_wheel._right_wheel_speed = right_wheel_speed;

    return _chassis_command;
}

VehicleVelocity DiffWheel::ForwardKinematic(const ChassisMotionModel& feedback)
{
    VehicleVelocity vehicleVelocity;

    double vl = feedback._diff_wheel._left_wheel_speed * _param._left_wheel_radius;
    double vr = feedback._diff_wheel._right_wheel_speed * _param._right_wheel_radius;

    double turning_radius = (((vl / vr) + 1) * _param._wheel_track / 2) / (1 - (vl / vr));
    double omega = vl / (turning_radius - _param._wheel_track / 2);
    double vx = omega * turning_radius;
    double vy = 0.0;
    vehicleVelocity = {vx, vy, omega};

    return vehicleVelocity;
}