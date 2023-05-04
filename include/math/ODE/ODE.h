#pragma once
#include <iostream>

// dy/dt = f(t, y)
class FirstOrderODE {
public:
    FirstOrderODE(float a, float b, float y0);
    ~FirstOrderODE();

    void solveRK2(float (*func)(float, float), float step);

    void print_sol();
    void save_to_csv(std::string dir, std::string separator);

    float** get_sol() { 
        return sol;
    }

private:
    float step, a, b, **sol = new float*[2], y0;
};