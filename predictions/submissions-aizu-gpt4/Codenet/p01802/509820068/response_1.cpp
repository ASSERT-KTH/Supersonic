#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int d, e;
    while (cin >> d >> e, d || e) {
        double min_gap = 1e9;
        for (int i = 0; i <= d; i++) {
            int j = d - i;
            double cost = sqrt(i * i + j * j);
            double gap = abs(cost - e);
            if (gap < min_gap) {
                min_gap = gap;
            }
        }
        cout << min_gap << "\n";
    }
    return 0;
}