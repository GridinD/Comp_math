#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return 1 / (1 + x*x);  
}

double integrate_rectangles(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        double x = a + i*h + h/2;
        sum += f(x);
    }
    return h*sum;
}

double integrate_trapezoid(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = (f(a) + f(b))/2.0;
    for (int i = 1; i < n; i++) {
        double x = a + i*h;
        sum += f(x);
    }
    return h*sum;
}

double integrate_simpson(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i++) {
        double x = a + i*h;
        if (i % 2 == 0) {
            sum += 2*f(x);
        } else {
            sum += 4*f(x);
        }
    }
    return h*sum/3.0;
}

int main() {
    double a = 0.0;
    double b = 1.0;
    int n = 1000;
    double integral_r = integrate_rectangles(a, b, n);
    double integral_t = integrate_trapezoid(a, b, n);
    double integral_s = integrate_simpson(a, b, n);

    cout << "Using rectangles method: " << integral_r << endl;
    cout << "Using trapezoid method: " << integral_t << endl;
    cout << "Using Simpson's method: " << integral_s << endl;

    return 0;
}
