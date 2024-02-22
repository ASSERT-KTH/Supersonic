#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    while (cin >> n >> k, n) {
        long long ac[n + 1], res = -LLONG_MAX;
        ac[0] = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> ac[i];
            ac[i] += ac[i - 1];
        }
        for (int i = k; i <= n; ++i) {
            res = max(res, ac[i] - ac[i - k]);
        }
        cout << res << '\n';
    }
    return 0;
}