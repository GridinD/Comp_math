#include <math.h>
#include <stdio.h>
const double aE = 0.999;
const double aI = 0.999;
const double k = 0.042;
const double p = 0.952;
const double b = 0.999;
const double M = 0.0188;
const double c_isol = 0;
const double y = 0;
const double a = 1;

double fC(double c_isol){
    return 1 + c_isol * (1 - 2 / 5 * a);
}

double fS(double S, double E, double I, double R, double N){
    return -1 * fC(c_isol) * S / N * (aI * I + aE * E) + y * R;
}

double dS(double S, double E, double I, double R, double N, double h){
    return h * fS(S + h / 2 * fS(S, E, I, R, N), E, I, R, N);
}

double fI(double E, double I){
    return k * E - b * I - M * I;
}

double dI(double E, double I, double h){
    return h * fI(E, I + h / 2 * fI(E, I));
}

double fE(double S, double E, double I, double N){
    return fC(c_isol) * S / N * (aI * I + aE * E) - (k + p) * E;
}

double dE(double S, double E, double I, double N, double h){
    return h * fE(S, E + h / 2 * fE(S, E, I, N), I, N);
}

double fR(double E, double I, double R){
    return b * I + p * E - y * R;
}

double dR(double E, double I, double R, double h){
    return h * fR(E, I, R + h / 2 * fR(E, I, R));
}

double fD(double I){
    return M * I;
}

double okr(double num, double znak){
    return round(num * pow(10, znak)) / pow(10, znak);
}

int main(int argc, char** argv){
    FILE* res;
    res = fopen("result.txt", "w");
    double t0 = 0;
    double T = 90;
    double h = 1;
    int n;
    n = (T - t0) / h;
    n++;
    double S[n];
    double E[n];
    double I[n];
    double R[n];
    double D[n];
    double N[n];
    double t[n];

    E[0] = 99;
    R[0] = 24;
    S[0] = 2798170 - E[0] - R[0];
    I[0] = 0;
    D[0] = 0;
    N[0] = E[0] + R[0]+ S[0] + I[0] + D[0];
    t[0] = t0;

    for (int i = 1; i < n; i++){
        t[i] = t0 + i * h;
        S[i] = S[i - 1] + dS(S[i - 1], E[i - 1], I[i - 1], R[i - 1], N[i - 1], h);
        E[i] = E[i - 1] + dE(S[i - 1], E[i - 1], I[i - 1], N[i - 1], h);
        I[i] = I[i - 1] + dI(E[i - 1], I[i - 1], h);
        R[i] = R[i - 1] + dR(E[i - 1], I[i - 1], R[i - 1], h);
        D[i] = D[i - 1] + fD(I[i - 1]);
        N[i] = S[i] + E[i] + I[i] + R[i] + D[i];
    }


    for (int i = 0; i < n; i++){
        fprintf(res, "%lf %.6lf %.6lf %.6lf %.6lf %.6lf %.6lf\n", okr(t[i], 2), okr(N[i], 2), okr(S[i], 2), okr(E[i], 2), okr(I[i], 2), okr(R[i], 2), okr(D[i],2));
        printf("%lf %.6lf %.6lf %.6lf %.6lf %.6lf %.6lf\n", okr(t[i], 2), okr(N[i], 2), okr(S[i], 2), okr(E[i], 2), okr(I[i], 2), okr(R[i], 2), okr(D[i],2));
    }
}