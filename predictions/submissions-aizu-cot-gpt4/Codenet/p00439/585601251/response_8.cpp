#include <iostream>
#include <climits>
using namespace std;

int main() {
  int n, k;
  while (cin >> n >> k, n) {
    long long res = -LLONG_MAX;
    long long cur_sum = 0, last_k_sum = 0;
    for (int i = 1; i <= n; ++i) {
      int num;
      cin >> num;
      cur_sum += num;
      if (i > k) {
        cur_sum -= last_k_sum;
      }
      if (i >= k) {
        res = max(res, cur_sum);
        last_k_sum = num;
      }
    }
    cout << res << endl;
  }
  return 0;
}