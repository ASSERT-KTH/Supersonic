#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int d, e;
    while (true) {
        cin >> d >> e;
        if (d == 0 && e == 0) break;
        double min = 1e10;
        double e_squared = e * e;
        for (int i = 0; i <= d; i++) {
            int j = d - i;
            double cost_squared = i * i + j * j;
            double gap_squared = (cost_squared - e_squared) * (cost_squared - e_squared);
            if (gap_squared < min) {
                min = gap_squared;
            }
        }
        cout << sqrt(min) << endl;
    }
    return 0;
}