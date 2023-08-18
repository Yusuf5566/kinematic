//
// Created by yuong on 23-8-18.
//

#ifndef KINEMATICS_DIFF_WHEEL_H
#define KINEMATICS_DIFF_WHEEL_H

#include "../vehicle.h"

namespace lingxi
{
namespace control
{

class DiffWheel : public Vehicle
{
public:
    virtual VehicleCommand ForwardKinematic(double vx, double vy, double omega) override;
};

}  // namespace control
}  // namespace lingxi

#endif  // KINEMATICS_DIFF_WHEEL_H
