//
// Created by yuong on 23-8-18.
//

#ifndef KINEMATICS_FOUR_MECANUM_H
#define KINEMATICS_FOUR_MECANUM_H
#include "../vehicle.h"

namespace lingxi
{
namespace control
{
class FourMecanum : public Vehicle
{
public:
    virtual VehicleCommand ForwardKinematic(double vx, double vy, double omega) override;
};

}  // namespace control
}  // namespace lingxi

#endif  // KINEMATICS_FOUR_MECANUM_H
