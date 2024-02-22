#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int C[6] = {1, 5, 10, 50, 100, 500};
int P;
int N[6];
const int T = 10000;
int dp[T];

int calc(int v) {
  int ans = 0;
  for (int i = 5; i >= 0; i--) {
    ans += v / C[i];
    v %= C[i];
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> P) {
    for (int i = 0; i < 6; i++) {
      cin >> N[i];
    }
    if (P == 0)
      break;

    fill_n(dp, T, 1001001001);
    dp[0] = 0;

    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < C[i]; j++) {
        deque<pair<int, int>> deq;
        for (int k = j; k < T; k += C[i]) {
          int w = T - k / C[i];
          dp[k] = min(dp[k], dp[k - C[i]] + w);

          while (!deq.empty() && deq.front().second + C[i] * N[i] < k) {
            deq.pop_front();
          }

          if (!deq.empty()) {
            dp[k] = min(dp[k], deq.front().first - w);
          }

          if (!deq.empty() && deq.front().second + N[i] * C[i] <= k) {
            deq.pop_front();
          }

          deq.push_back({dp[k] + w, k});
        }
      }
    }

    int mi = 1001001001;
    for (int i = P; i < T; i++) {
      mi = min(mi, dp[i] + calc(i - P));
    }

    cout << mi << endl;
  }

  return 0;
}