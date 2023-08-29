//
// Created by yuong on 23-8-18.
//

#ifndef KINEMATICS_SINGLE_HELM_H
#define KINEMATICS_SINGLE_HELM_H

#include "../vehicle.h"

class SingleHelm : public Vehicle
{
public:
    virtual ChassisMotionModel InverseKinematic(double vx, double vy, double omega) override;
    virtual VehicleVelocity ForwardKinematic(const ChassisMotionModel& feedback) override;

private:
    SingleHelmParam _param;

};


#endif  // KINEMATICS_SINGLE_HELM_H
