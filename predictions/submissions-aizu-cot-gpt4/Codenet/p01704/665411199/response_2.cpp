#include <iostream>
#include <cstdio>
#define MAX 100001
#define inf 1e9

int n, pw;
double vw[MAX], pf[MAX], vf[MAX], th[MAX], precalc[MAX];

double f(double W) {
    double cost = W * pw;
    for (int i = 0; i < n; i++) {
        double sum1 = precalc[i] - th[i];
        if (sum1 > 0) {
            double sum2 = sum1 / vf[i];
            cost += sum2 * pf[i];
        }
    }
    return cost;
}

int main() {
    while (1) {
        std::cin >> n >> pw;
        if (n == 0)
            break;
        for (int i = 0; i < n; i++) {
            std::cin >> vw[i] >> pf[i] >> vf[i] >> th[i];
            precalc[i] = vw[i];
        }
        double l = 0, r = inf;
        double m1 = (l * 2.0 + r) / 3.0;
        double m2 = (l + r * 2.0) / 3.0;
        double res1 = f(m1);
        double res2 = f(m2);
        for (int i = 0; i < 200; i++) {
            if (res1 < res2)
                r = m2;
            else
                l = m1;
            m1 = (l * 2.0 + r) / 3.0;
            m2 = (l + r * 2.0) / 3.0;
            res1 = f(m1);
            res2 = f(m2);
        }
        printf("%.4f\n", f(l));
    }
    return 0;
}