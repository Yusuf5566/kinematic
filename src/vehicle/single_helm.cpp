//
// Created by yuong on 23-8-18.
//

#include "single_helm.h"

namespace lingxi
{
namespace control
{
VehicleCommand SingleHelm::ForwardKinematic(double vx, double vy, double omega)
{
    double wheel_radius = 0.325;
    double wheel_base = 2.2;
    double _front_wheel_offset = 0;

    double v = sqrt(vx * vx + vy * vy);
    double l = sqrt(wheel_base * wheel_base + _front_wheel_offset * _front_wheel_offset);
    double delta = atan((omega * l) / v);

    double speed = v * cos(delta) / wheel_radius;
    double angel = delta;

    _vehicle_command._single_helm._speed = speed;
    _vehicle_command._single_helm._angel = angel;

    std::cout << "angel=" << _vehicle_command._single_helm._angel << " speed=" << _vehicle_command._single_helm._speed
              << std::endl;
    return _vehicle_command;
};

}  // namespace control
}  // namespace lingxi