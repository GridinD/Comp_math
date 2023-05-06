#include <iostream>
#include <vector>

using namespace std;

double aitken_interpolation(const vector<double>& x, const vector<double>& y, double xi) {
    int n = x.size();
    vector<double> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = y[i];
    }
    for (int k = 1; k < n; k++) {
        for (int i = 0; i < n-k; i++) {
            p[i] = ((xi - x[i+k]) * p[i] + (x[i] - xi) * p[i+1]) / (x[i] - x[i+k]);
        }
    }
    return p[0];
}

int main() {
    vector<double> x = {1.0, 2.0, 3.0, 4.0, 5.0};
    vector<double> y = {1.6, 2.7, 3.8, 4.9, 5.1};
    double xi = 4.6;
    double result = aitken_interpolation(x, y, xi);
    cout << "Interpolated value at x = " << xi << " is " << result << endl;
    return 0;
}
