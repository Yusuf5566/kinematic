//
// Created by yuong on 23-8-18.
//

#ifndef KINEMATICS_FOUR_MECANUM_H
#define KINEMATICS_FOUR_MECANUM_H
#include "../vehicle.h"

class FourMecanum : public Vehicle
{
public:
    virtual ChassisMotionModel InverseKinematic(double vx, double vy, double omega) override;
    virtual VehicleVelocity ForwardKinematic(const ChassisMotionModel& feedback) override;

private:
    FourMecanumParam _param;

};



#endif  // KINEMATICS_FOUR_MECANUM_H
