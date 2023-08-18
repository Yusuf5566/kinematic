//
// Created by yuong on 23-8-18.
//

#include "four_mecanum.h"
namespace lingxi
{
namespace control
{

VehicleCommand FourMecanum::ForwardKinematic(double vx, double vy, double omega)
{
    double wheel_radius = 0.225;
    double weight = 1.6;
    double length = 2.8;

    double front_left_speed = (vx - vy - (weight + length) / 2 * omega) / wheel_radius;
    double front_right_speed = (vx + vy + (weight + length) / 2 * omega) / wheel_radius;
    double rear_left_speed = (vx + vy - (weight + length) / 2 * omega) / wheel_radius;
    double rear_right_speed = (vx - vy + (weight + length) / 2 * omega) / wheel_radius;

    _vehicle_command._four_mecanum._front_left_wheel_speed = front_left_speed;
    _vehicle_command._four_mecanum._front_right_wheel_speed = front_right_speed;
    _vehicle_command._four_mecanum._rear_left_wheel_speed = rear_left_speed;
    _vehicle_command._four_mecanum._rear_right_wheel_speed = rear_right_speed;

    std::cout << "front_left_speed=" << _vehicle_command._four_mecanum._front_left_wheel_speed
              << " front_right_speed=" << _vehicle_command._four_mecanum._front_right_wheel_speed
              << " rear_left_speed=" << _vehicle_command._four_mecanum._rear_left_wheel_speed
              << " rear_right_speed=" << _vehicle_command._four_mecanum._rear_right_wheel_speed<< std::endl;

    return _vehicle_command;
};

}  // namespace control
}  // namespace lingxi