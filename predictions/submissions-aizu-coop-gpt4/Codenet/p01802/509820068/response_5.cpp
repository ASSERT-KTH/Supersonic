#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int d, e;
    while (1) {
        cin >> d >> e;
        if (d == 0 && e == 0)
            break;

        double min_gap_squared = 1e10;
        e *= e;  // Squaring 'e' here to avoid sqrt in the loop.
        for (int i = 0; i <= d; i++) {
            int j = d - i;
            double cost_squared = i * i + j * j;
            double gap_squared = (cost_squared - e) * (cost_squared - e);
            if (gap_squared < min_gap_squared) {
                min_gap_squared = gap_squared;
            }
        }
        cout << sqrt(min_gap_squared) << "\n";
    }
    return 0;
}