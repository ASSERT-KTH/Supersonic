#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    while (cin >> n >> k, n) {
        vector<long long> ac(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> ac[i];
            ac[i] += ac[i - 1];
        }
        long long res = ac[k];
        for (int i = k + 1; i <= n; ++i) {
            res = max(res, ac[i] - ac[i - k]);
        }
        cout << res << '\n';
    }
    return 0;
}