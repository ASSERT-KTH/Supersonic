#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

constexpr int C[] = {1, 5, 10, 50, 100, 500};
constexpr int T = 10000;

int calc(int v) {
  int ans = 0;
  for (int i = 5; i >= 0; i--) {
    ans += v / C[i];
    v %= C[i];
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int P;
  while (cin >> P) {
    if (P == 0)
      break;
    vector<int> N(6);
    for (int i = 0; i < 6; i++)
      cin >> N[i];

    vector<int> dp(T, 1001001001);
    int cnt = 0;
    for (int i = 5; i >= 0; i--) {
      while (P - C[i] >= 2500 && N[i]) {
        cnt++;
        N[i]--;
        P -= C[i];
      }
      if (N[i])
        break;
    }
    dp[0] = 0;
    for (int i = 0; i < 6; i++) {
      for (int j = C[i] - 1; j < T; j += C[i]) {
        deque<pair<int, int>> deq;
        for (int k = j; k < T; k += C[i]) {
          int w = T - k / C[i];
          dp[k] = min(dp[k], dp[k - C[i]]);
          while (!deq.empty() && deq.front().second + C[i] * N[i] < k)
            deq.pop_front();
          if (!deq.empty())
            dp[k] = min(dp[k], deq.front().first - w);
          if (!deq.empty() && deq.front().second + N[i] * C[i] == k)
            deq.pop_front();
          deq.push_back(make_pair(dp[k] + w, k));
        }
      }
    }
    int mi = 1001001001;
    for (int i = P; i < T; i++) {
      mi = min(mi, dp[i] + calc(i - P));
    }
    cout << mi + cnt << endl;
  }

  return 0;
}