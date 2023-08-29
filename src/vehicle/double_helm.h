//
// Created by yuong on 23-8-18.
//

#ifndef KINEMATICS_DOUBLE_HELM_H
#define KINEMATICS_DOUBLE_HELM_H

#include "../vehicle.h"

class DoubleHelm : public Vehicle
{
public:
    virtual ChassisMotionModel InverseKinematic(double vx, double vy, double omega) override;
    virtual VehicleVelocity ForwardKinematic(const ChassisMotionModel& feedback) override;

private:
    DoubleHelmParam _param;
};


#endif  // KINEMATICS_DOUBLE_HELM_H
