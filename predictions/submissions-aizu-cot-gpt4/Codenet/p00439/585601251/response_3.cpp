#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

int main() {
    int n, k;
    while (cin >> n >> k, n) {
        long long sum = 0, prev_sum = 0, num, res = -LLONG_MAX;
        for (int i = 1; i <= n; ++i) {
            cin >> num;
            sum += num;
            if (i > k) {
                sum -= prev_sum;
            }
            if (i >= k) {
                res = max(res, sum);
                prev_sum = num;
            }
        }
        cout << res << endl;
    }
    return 0;
}