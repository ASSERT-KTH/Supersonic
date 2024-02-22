#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, k;
  while (cin >> n >> k, n) {
    vector<long long> ac(n + 1, 0);
    ac.reserve(n + 1);  // reserve memory in advance

    for (int i = 1; i <= n; ++i) {
      cin >> ac[i];
      ac[i] += ac[i - 1];
    }

    // Initialize the maximum sum with the sum of the first subsequence
    long long res = ac[k];

    // Use a sliding window to calculate the maximum sum
    for (int i = k + 1; i <= n; ++i) {
      long long sum = ac[i] - ac[i - k];
      res = max(res, sum);
    }

    cout << res << endl;
  }

  return 0;
}