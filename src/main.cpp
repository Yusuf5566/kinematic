//
// Created by yuong on 23-8-14.
//
#include "vehicle.h"
#include "vehicle/diff_wheel.h"
#include "vehicle/double_helm.h"
#include "vehicle/four_mecanum.h"
#include "vehicle/single_helm.h"

int main()
{
    lingxi::control::Vehicle* v1 = new lingxi::control::DoubleHelm();
    lingxi::control::Vehicle* v2 = new lingxi::control::SingleHelm();
    lingxi::control::Vehicle* v3 = new lingxi::control::DiffWheel();
    lingxi::control::Vehicle* v4 = new lingxi::control::FourMecanum();

    v2->ForwardKinematic(12, 2, 3);
    std::cout << std::endl;
    v1->ForwardKinematic(12, 1, 3);
    std::cout << std::endl;
    v3->ForwardKinematic(12, 2, 3);
    std::cout << std::endl;
    v4->ForwardKinematic(12, 2, 3);

    return 0;
}