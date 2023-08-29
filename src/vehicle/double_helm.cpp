//
// Created by yuong on 23-8-18.
//

#include "double_helm.h"

// 横摆角：theta
// 侧偏角：delta

ChassisMotionModel DoubleHelm::InverseKinematic(double vx, double vy, double omega)
{
    double front_location = sqrt(
        (_param._wheel_base / 2) * (_param._wheel_base / 2) + _param._front_wheel_offset * _param._front_wheel_offset);
    double rear_location = sqrt(
        (_param._wheel_base / 2) * (_param._wheel_base / 2) + _param._rear_wheel_offset * _param._rear_wheel_offset);
    double front_v = 0.0;
    double rear_v = 0.0;
    double front_delta = 0.0;
    double rear_delta = 0.0;

    double epsilon = 1.0e-6;
    if (omega < epsilon)
    {
        front_v = vx / _param._front_wheel_radius;
        rear_v = vx / _param._rear_wheel_radius;
        _chassis_command._double_helm._front_wheel_angel = front_delta;
        _chassis_command._double_helm._rear_wheel_angel = rear_delta;
        _chassis_command._double_helm._front_wheel_speed = front_v / _param._front_wheel_radius;
        _chassis_command._double_helm._rear_wheel_speed = rear_v / _param._rear_wheel_radius;

        return _chassis_command;
    }

    double v = sqrt(vx * vx + vy * vy);
    double theta = atan(vy / vx);
    double turning_radius = v / omega;
    front_delta = atan((front_location + turning_radius * sin(theta)) / (turning_radius * cos(theta)));
    rear_delta = atan((rear_location - turning_radius * sin(theta)) / (turning_radius * cos(theta)));
    double front_turning_radius =
        sqrt((turning_radius * cos(theta)) * (turning_radius * cos(theta)) +
             (front_location + turning_radius * sin(theta)) * (front_location + turning_radius * sin(theta)));
    double rear_turning_radius =
        sqrt((turning_radius * cos(theta)) * (turning_radius * cos(theta)) +
             (rear_location - turning_radius * sin(theta)) * (front_location + turning_radius * sin(theta)));
    front_v = omega * front_turning_radius;
    rear_v = omega * rear_turning_radius;

    _chassis_command._double_helm._front_wheel_angel = front_delta;
    _chassis_command._double_helm._rear_wheel_angel = rear_delta;
    _chassis_command._double_helm._front_wheel_speed = front_v / _param._front_wheel_radius;
    _chassis_command._double_helm._rear_wheel_speed = rear_v / _param._rear_wheel_radius;

    return _chassis_command;
}

VehicleVelocity DoubleHelm::ForwardKinematic(const ChassisMotionModel& feedback)
{
    VehicleVelocity vehicleVelocity;

    double front_location = sqrt(
        (_param._wheel_base / 2) * (_param._wheel_base / 2) + _param._front_wheel_offset * _param._front_wheel_offset);
    double rear_location = sqrt(
        (_param._wheel_base / 2) * (_param._wheel_base / 2) + _param._rear_wheel_offset * _param._rear_wheel_offset);
    double turning_radius_cos_delta =
        (front_location + rear_location) / (tan(feedback._double_helm._front_wheel_angel) +
                                               tan(feedback._double_helm._rear_wheel_angel));
    double turning_radius_sin_delta =
        tan(feedback._double_helm._front_wheel_angel) * turning_radius_cos_delta - front_location;
    double turning_radius =
        sqrt(turning_radius_cos_delta * turning_radius_cos_delta + turning_radius_sin_delta * turning_radius_sin_delta);

    double delta = (front_location + rear_location) / ((tan(feedback._double_helm._front_wheel_angel) +
                                                           tan(feedback._double_helm._rear_wheel_angel)) *
                                                          turning_radius);
    double front_turning_radius =
        turning_radius_cos_delta / cos(feedback._double_helm._front_wheel_angel);
    double omega =
        feedback._double_helm._front_wheel_speed * _param._front_wheel_radius / front_turning_radius;
    double v = omega * turning_radius;
    double vx = v* cos(delta);
    double vy = v* sin(delta);
    vehicleVelocity={vx, vy, omega};

    return vehicleVelocity;
}

