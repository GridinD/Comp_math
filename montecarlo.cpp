#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

double monte_carlo_pi(int n) {
    srand(time(NULL));
    int count = 0;
    for (int i = 0; i < n; i++) {
        double x = (double) rand() / RAND_MAX;
        double y = (double) rand() / RAND_MAX;
        if (sqrt(x * x + y * y) <= 1) {
            count++;
        }
    }
    return 4.0 * count / n;
}

int main() {
    int n = 10000000;
    cout << "Approximate value of pi: " << monte_carlo_pi(n) << endl;
    return 0;
}
