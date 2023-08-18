//
// Created by yuong on 23-8-18.
//

#include "double_helm.h"

// 横摆角：theta
// 侧偏角：delta

namespace lingxi
{
namespace control
{
VehicleCommand DoubleHelm::ForwardKinematic(double vx, double vy, double omega)
{
    double wheel_radius = 0.325;
    double wheel_base = 2.2;
    double _front_wheel_offset = 0.0;
    double _rear_wheel_offset = 0.0;
    double front_location = sqrt((wheel_base / 2) * (wheel_base / 2) + _front_wheel_offset * _front_wheel_offset);
    double rear_location = sqrt((wheel_base / 2) * (wheel_base / 2) + _rear_wheel_offset * _rear_wheel_offset);

    double v = sqrt(vx * vx + vy * vy);
    double theta = atan(vy / vx);
    double turning_radius = v / omega;
    double front_delta = atan((front_location + turning_radius * sin(theta)) / (turning_radius * cos(theta)));
    double rear_delta = atan((rear_location - turning_radius * sin(theta)) / (turning_radius * cos(theta)));
    double front_turning_radius =
        sqrt((turning_radius * cos(theta)) * (turning_radius * cos(theta)) +
             (front_location + turning_radius * sin(theta)) * (front_location + turning_radius * sin(theta)));
    double rear_turning_radius =
        sqrt((turning_radius * cos(theta)) * (turning_radius * cos(theta)) +
             (rear_location - turning_radius * sin(theta)) * (front_location + turning_radius * sin(theta)));
    double front_v = omega * front_turning_radius;
    double rear_v = omega * rear_turning_radius;

    _vehicle_command._double_helm._front_wheel_angel = front_delta;
    _vehicle_command._double_helm._rear_wheel_angel = rear_delta;
    _vehicle_command._double_helm._front_wheel_speed = front_v / wheel_radius;
    _vehicle_command._double_helm._rear_wheel_speed = rear_v / wheel_radius;

    std::cout<<"front_v="<<front_v<<" rear_v="<<rear_v
        <<" front_delta="<<front_delta<<" rear_delta"<<rear_delta<<std::endl;

    return _vehicle_command;
};

}  // namespace control
}  // namespace lingxi