//
// Created by yuong on 23-8-16.
//

#ifndef __VEHICLE_MODEL_H__
#define __VEHICLE_MODEL_H__

#include <iostream>

struct SingleHelmModel
{
    double _speed;
    double _angel;
    //  double _front_wheel_offset;
};

struct DoubleHelmModel
{
    double _front_wheel_speed;
    double _rear_wheel_speed;
    double _front_wheel_angel;
    double _rear_wheel_angel;
};

struct DiffWheelModel
{
    double _left_wheel_speed;
    double _right_wheel_speed;
};

struct FourMecanumModel
{
    double _front_left_wheel_speed;
    double _front_right_wheel_speed;
    double _rear_left_wheel_speed;
    double _rear_right_wheel_speed;
};

union ChassisMotionModel
{
    SingleHelmModel _single_helm;
    DoubleHelmModel _double_helm;
    DiffWheelModel _diff_wheel;
    FourMecanumModel _four_mecanum;
};

struct VehicleVelocity
{
    double _vx;
    double _vy;
    double _omwga;
};

#endif
