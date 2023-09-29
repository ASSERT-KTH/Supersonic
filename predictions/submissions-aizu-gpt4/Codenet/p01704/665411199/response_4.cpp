#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define MAX 100001
#define inf 1e9

struct Item {
    double vw, pf, vf, th;
};

std::vector<Item> items(MAX);
int n;
double pw;

double f(double W) {
    double cost = W * pw;
    for (int i = 0; i < n; i++) {
        if (W * items[i].vw > items[i].th)
            continue;
        double sum1 = items[i].th - W * items[i].vw;
        double sum2 = sum1 / items[i].vf;
        cost += sum2 * items[i].pf;
    }
    return cost;
}

int main() {
    while (std::cin >> n >> pw && n) {
        for (int i = 0; i < n; i++)
            std::cin >> items[i].vw >> items[i].pf >> items[i].vf >> items[i].th;
        double l = 0, r = inf;
        for (int i = 0; i < 200; i++) {
            double m1 = (l * 2 + r) / 3;
            double m2 = (l + r * 2) / 3;
            if (f(m1) < f(m2))
                r = m2;
            else
                l = m1;
        }
        printf("%.4f\n", f(l));
    }
    return 0;
}