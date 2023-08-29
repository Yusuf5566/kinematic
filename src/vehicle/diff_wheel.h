//
// Created by yuong on 23-8-18.
//

#ifndef KINEMATICS_DIFF_WHEEL_H
#define KINEMATICS_DIFF_WHEEL_H

#include "../vehicle.h"


class DiffWheel : public Vehicle
{
public:
    virtual ChassisMotionModel InverseKinematic(double vx, double vy, double omega) override;
    virtual VehicleVelocity ForwardKinematic(const ChassisMotionModel& feedback) override;

private:
    DiffWheelParam _param;

};


#endif  // KINEMATICS_DIFF_WHEEL_H
