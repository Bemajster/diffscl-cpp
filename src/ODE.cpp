#include "math/ODE/ODE.h"
#include <math.h>
#include <fstream>

FirstOrderODE::FirstOrderODE(float p_a, float p_b, float p_y0) {
    a = p_a;
    b = p_b;
    y0 = p_y0;
}

FirstOrderODE::~FirstOrderODE() {
    delete sol;
}

void FirstOrderODE::solveRK2(float (*func)(float, float), float p_step) {
    step = p_step;

    int arr_size = ceil((b - a) / step) + 1;

    sol[0] = new float[arr_size];
    sol[1] = new float[arr_size];

    sol[1][0] = y0;

    for(int i = 0; i < arr_size; i++) {
        sol[0][i] = a + i * step;
    }

    for(int i = 0; i < arr_size; i++) {
        sol[1][i + 1] = sol[1][i] + step * func(a + i * step, sol[1][i]);
    }
}

void FirstOrderODE::print_sol() {
    for(int i = 0; i < ceil((b - a) / step) + 1; i++) {
        std::cout << "t = " << sol[0][i] << " => x1 = " << sol[1][i] << '\n';
    }
}

void FirstOrderODE::save_to_csv(std::string dir, std::string separator) {
    std::fstream file;
    file.open(dir, std::ios::out);

    for(int i = 0; i < ceil((b - a) / step) + 1; i++) {
        file << sol[0][i] << separator << sol[1][i] << std::endl;
    }

    file.close();
}