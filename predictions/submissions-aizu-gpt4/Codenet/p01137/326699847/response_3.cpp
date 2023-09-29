#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int e;

    while (cin >> e, e) {
        int m = 1000000;
        for (int z = cbrt(e); z >= 0; --z) {
            int val = z * z * z;
            for (int y = sqrt(e - val); y >= 0; --y) {
                int val2 = val + y * y;
                if (val2 > e) break;
                m = min(m, (e - val2) + y + z);
            }
        }
        cout << m << "\n";
    }
    return 0;
}