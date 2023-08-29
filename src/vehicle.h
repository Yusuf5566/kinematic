//
// Created by yuong on 23-8-16.
//

#ifndef __VEHICLE_H__
#define __VEHICLE_H__
#include "conf/vehicle_conf.h"
#include "conf/vehicle_model.h"
#include <cmath>


class Vehicle
{
public:
    virtual ChassisMotionModel InverseKinematic(double vx, double vy, double omega) = 0;
    virtual VehicleVelocity ForwardKinematic(const ChassisMotionModel& feedback) = 0;

protected:
    ChassisMotionModel _chassis_command;

};

#endif  // __VEHICLE_H__
