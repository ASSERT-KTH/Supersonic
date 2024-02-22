#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int e;
    while (cin >> e, e) {
        int ans = INT_MAX;
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