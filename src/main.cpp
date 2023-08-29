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
    Vehicle* v1 = new DoubleHelm();
    Vehicle* v2 = new SingleHelm();
    Vehicle* v3 = new DiffWheel();
    Vehicle* v4 = new FourMecanum();

    v2->InverseKinematic(12, 2, 0.5);
    std::cout << std::endl;
    v1->InverseKinematic(12, 1, 0.5);
    std::cout << std::endl;
    v3->InverseKinematic(12, 2, 3);
    std::cout << std::endl;
    v4->InverseKinematic(12, 2, 3);

    return 0;
}