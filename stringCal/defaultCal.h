#pragma once

#include"include.h"

class Calculator {
private:
    double a, b, c;
public:
    Calculator() {
        std::cout << "Enter Number 1: ";
        std::cin >> a;
        std::cout << "Enter Number 2: ";
        std::cin >> b;
    }
    Calculator(double a, double b, double c) : a(a), b(b), c(c) {}

    double sum() {
        return a + b;
    }

    double minus() {
        return a - b;
    }

    double div() {
        try {
            if (b == 0) {
                throw 123;
            }
            else {
                return a / b;
            }
        }
        catch (int i) {
            std::cout << "Error Divide Zero" << std::endl;
        }
        return 0;
    }

    double mult() {
        return a * b;
    }

    void sqrEquations() {
        double res;
        double x1, x2;
        res = (b * b) - 4 * a * c;
        x1 = (-b + std::sqrt(res)) / 2 * a;
        x2 = (-b - std::sqrt(res)) / 2 * a;
        if (x1 > x2) {
            std::cout << x1;
        }
        else {
            std::cout << x2;
        }
    }

    double powD() {
        double res = 1;
        double A = a;
        for (int i = 1; i < b; ++i) {
            a *= A;
        }
        return a;
    }

};


