#include <iostream>
#include <cmath>

using namespace std;

double f(double x, double y) {
    return x * y + pow(x, 2);
}

int main() {
    double x0 = 0.0;            
    double y0 = 1.0;           
    double h = 0.1;             
    double x = x0;           
    double y = y0;              

    cout << "At x = " << x << ", y = " << y << endl;

    double x_end = 1.0;
    while (x < x_end) {
        y += h * f(x, y);       
        x += h;                 
        cout << "At x = " << x << ", y = " << y << endl;
    }

    return 0;
}
