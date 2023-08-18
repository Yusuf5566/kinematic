//
// Created by yuong on 23-8-16.
//

#ifndef __VEHICLE_H__
#define __VEHICLE_H__
#include <cmath>
#include "vehicle_model.h"

using namespace lingxi::common;
namespace lingxi
{
namespace control
{

class Vehicle
{
public:
    virtual VehicleCommand ForwardKinematic(double vx, double vy, double omega) = 0;

protected:
    VehicleCommand _vehicle_command;
};

}  // namespace control
}  // namespace lingxi

#endif  // __VEHICLE_H__
