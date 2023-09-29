#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int e;
    while (cin >> e, e) {
        int m = 1000000;
        int sqrt_e = sqrt(e);
        for (int z = sqrt_e; z >= 0; --z) {
            int val = z * z * z;
            if (val > e)
                continue;
            int sqrt_e_val = sqrt(e - val);
            for (int y = sqrt_e_val; y >= 0; --y) {
                int val2 = val + y * y;
                if (val2 > e)
                    continue;
                m = min(m, (e - val2) + y + z);
                break;
            }
        }
        cout << m << endl;
    }
    return 0;
}