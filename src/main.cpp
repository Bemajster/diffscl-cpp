#include <iostream>
#include "math/ODE/ODE.h"

using namespace std;

float func(float t, float y) {
    return -y;
}

int main() {
    FirstOrderODE* e = new FirstOrderODE(0, 5, 1);
    e->solveRK2(&func, 0.001);
    e->save_to_csv("exponential_dec.csv", ";");

    return 0;
}