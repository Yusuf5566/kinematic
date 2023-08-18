//
// Created by yuong on 23-8-18.
//

#include "diff_wheel.h"

namespace lingxi
{
namespace control
{

VehicleCommand DiffWheel::ForwardKinematic(double vx, double vy, double omega)
{
    double wheel_radius = 0.325;
    double wheel_spacing = 2.5;
    double v = sqrt(vx * vx + vy * vy);
    double epsilon = 1.0e-6;
    if (omega < epsilon)
    {
        _vehicle_command._diff_wheel._left_wheel_speed = v;
        _vehicle_command._diff_wheel._right_wheel_speed = v;
        return _vehicle_command;
    }
    double turning_radius = v / omega;
    double left_wheel_speed = omega * (turning_radius - wheel_spacing / 2) / wheel_radius;
    double right_wheel_speed = omega * (turning_radius + wheel_spacing / 2) / wheel_radius;

    _vehicle_command._diff_wheel._left_wheel_speed = left_wheel_speed;
    _vehicle_command._diff_wheel._right_wheel_speed = right_wheel_speed;

    std::cout << "left_wheel_speed=" << _vehicle_command._diff_wheel._left_wheel_speed << " right_wheel_speed="
              << _vehicle_command._diff_wheel._right_wheel_speed << std::endl;

    return _vehicle_command;
};

}  // namespace control
}  // namespace lingxi