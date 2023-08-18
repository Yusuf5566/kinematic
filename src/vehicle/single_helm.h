//
// Created by yuong on 23-8-18.
//

#ifndef KINEMATICS_SINGLE_HELM_H
#define KINEMATICS_SINGLE_HELM_H

#include "../vehicle.h"

namespace lingxi
{
namespace control
{

class SingleHelm : public Vehicle
{
public:
    virtual VehicleCommand ForwardKinematic(double vx, double vy, double omega) override;
};

}  // namespace control
}  // namespace lingxi
#endif  // KINEMATICS_SINGLE_HELM_H
