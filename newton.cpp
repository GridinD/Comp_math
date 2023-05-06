#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return x*x*x +4*x - 3;
}

double df(double x) {
    return 3*(x*x) + 4;
}

double newton(double x, double eps, double (*f)(double), double (*df)(double)) {
    double fx = f(x);
    int iter = 0;
    while (abs(fx) > eps) {
        double dfx = df(x);
        if (dfx == 0) {
            cerr << "Ошибка: производная равна нулю" << endl;
            exit(1);
        }
        x = x - fx / dfx;
        fx = f(x);
    }
    return x;
}

int main() {
    double x0 = 0; 
    double eps = 0.001; 
    double root = newton(x0, eps, f, df); 
    cout << "Корень уравнения: " << root << endl;
    return 0;
}