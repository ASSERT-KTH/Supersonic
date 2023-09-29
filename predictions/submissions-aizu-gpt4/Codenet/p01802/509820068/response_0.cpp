#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int d, e;
    while (cin >> d >> e && (d || e)) {
        double min = 1e9;
        for (int i = 0; i <= d; ++i) {
            int j = d - i;
            double cost = sqrt(i * i + j * j);
            double gap = fabs(cost - e);
            if (gap < min) {
                min = gap;
            }
        }
        cout.precision(4);
        cout << min << '\n';
    }
    return 0;
}