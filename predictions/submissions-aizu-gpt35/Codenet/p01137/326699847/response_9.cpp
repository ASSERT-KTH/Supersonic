#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int e;
    while (cin >> e, e) {
        int m = 1000000;
        for (int z = 100; z >= 0; --z) {
            int val = z * z * z;
            if (val > e) continue;
            int val2 = e - val;
            if (val2 == 0) {
                m = z;
                break;
            }
            int y = sqrt(val2);
            if (y * y != val2) ++y;
            if (y * y + val > e) continue;
            m = min(m, y + z + (e - y * y - val));
        }
        cout << m << endl;
    }
    return 0;
}