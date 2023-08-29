//
// Created by yuong on 23-8-18.
//

#include "single_helm.h"

ChassisMotionModel SingleHelm::InverseKinematic(double vx, double vy, double omega)
{
    double v = sqrt(vx * vx + vy * vy);
    double speed = 0.0;
    double delta = 0.0;
    double epsilon = 1.0e-6;
    if (omega < epsilon)
    {

        speed = v / _param._wheel_radius;
        _chassis_command._single_helm._speed = speed;
        _chassis_command._single_helm._angel= delta;
        return _chassis_command;
    }

    double turning_radius = v / omega;

    if (omega > 0)
    {
        speed = ((turning_radius + _param._front_wheel_offset) * omega / cos(delta)) / _param._wheel_radius;
        delta = atan(_param._wheel_base / (turning_radius + _param._front_wheel_offset));
    }
    else
    {
        speed = ((turning_radius - _param._front_wheel_offset) * omega / cos(delta)) / _param._wheel_radius;
        delta = -atan(_param._wheel_base / (turning_radius - _param._front_wheel_offset));
    }

    _chassis_command._single_helm._speed = speed;
    _chassis_command._single_helm._angel = delta;

    std::cout<<"speed="<<_chassis_command._single_helm._speed<<std::endl;
    std::cout<<"delta="<<_chassis_command._single_helm._angel<<std::endl;

    return _chassis_command;
}

VehicleVelocity SingleHelm::ForwardKinematic(const ChassisMotionModel& feedback)
{
    double epsilon = 1.0e-6;
    double wheel_v = feedback._single_helm._speed * _param._wheel_radius;
    double omega = 0.0;
    double v = 0.0;
    VehicleVelocity vehicleVelocity;

    if (feedback._single_helm._angel < epsilon)
    {
        v = wheel_v;
        vehicleVelocity = {v, 0.0, omega};
        return vehicleVelocity;
    }

    if (feedback._single_helm._angel > 0)
    {
        double wheel_turning_radius = (_param._wheel_base / sin(feedback._single_helm._angel));
        omega = wheel_v / wheel_turning_radius;
        v = omega *
            (wheel_turning_radius * cos(feedback._single_helm._angel) - _param._front_wheel_offset);
    }
    else
    {
        double wheel_turning_radius = (_param._wheel_base / sin(feedback._single_helm._angel));
        omega = wheel_v / wheel_turning_radius;
        v = omega *
            (wheel_turning_radius * cos(feedback._single_helm._angel) + _param._front_wheel_offset);
    }

    vehicleVelocity = {v, 0.0, omega};

    return vehicleVelocity;
}