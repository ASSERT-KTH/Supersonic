#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int e;
    while (cin >> e, e) {
        int ans = inf;
        for (int z = cbrt(e); z >= 0; --z) {
            int y_limit = sqrt(e - z * z * z);
            for (int y = y_limit; y >= 0; --y) {
                int x = e - y * y - z * z * z;
                ans = min(ans, x + y + z);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}