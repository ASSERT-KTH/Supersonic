#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int e;
    while (cin >> e, e) {
        int m = 1000000;
        int maxZ = cbrt(e);
        for (int z = maxZ; z >= 0; --z) {
            int val = z * z * z;
            int maxY = sqrt(e - val);
            for (int y = maxY; y >= 0; --y) {
                int val2 = val + y * y;
                m = min(m, (e - val2) + y + z);
            }
        }
        cout << m << endl;
    }
    return 0;
}