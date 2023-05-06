#include <iostream>
#include <vector>

using namespace std;

double newton_interpolation(vector<double> x, vector<double> y, double xi) {
    int n = x.size();

    vector<vector<double>> div_diff(n, vector<double>(n));
    for (int i = 0; i < n; i++) {
        div_diff[i][0] = y[i];
    }
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n-j; i++) {
            div_diff[i][j] = (div_diff[i+1][j-1] - div_diff[i][j-1]) / (x[i+j] - x[i]);
        }
    }

    double result = y[0];
    double prod = 1.0;
    for (int j = 1; j < n; j++) {
        prod *= (xi - x[j-1]);
        result += div_diff[0][j] * prod;
    }

    return result;
}

int main() {
  
    vector<double> x;
    x.push_back(1.0);
    x.push_back(2.0);
    x.push_back(3.0);
    x.push_back(4.0);
    x.push_back(5.0);

    vector<double> y;
    y.push_back(1.6);
    y.push_back(2.7);
    y.push_back(3.8);
    y.push_back(4.9);
    y.push_back(5.1);

    
    double xi = 4.6;
    double result = newton_interpolation(x, y, xi);

   
    cout << "Interpolated value at x = " << xi << " is " << result << endl;

    return 0;
}
