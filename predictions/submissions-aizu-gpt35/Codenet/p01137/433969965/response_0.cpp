#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int e;
    while (cin >> e, e) {
        int ans = 1000;
        for (int z = 0; z * z * z <= e; ++z) {
            for (int y = 0; y * y + z * z * z <= e; ++y) {
                int x = e - (y * y + z * z * z);
                ans = min(ans, x + y + z);
            }
        }
        cout << ans << endl;
    }
    return 0;
}