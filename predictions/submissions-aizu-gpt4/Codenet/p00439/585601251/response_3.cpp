#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, k;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n >> k, n) {
        vector<long long> ac(n + 1, 0);
        long long res = -LLONG_MAX;
        for (int i = 1; i <= n; ++i) {
            cin >> ac[i];
            ac[i] += ac[i - 1];
            if(i >= k) {
                res = max(res, ac[i] - ac[i - k]);
            }
        }
        cout << res << '\n';
    }
    return 0;
}