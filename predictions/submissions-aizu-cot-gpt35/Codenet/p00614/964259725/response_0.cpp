#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

const int T = 10000;
int C[6] = {1, 5, 10, 50, 100, 500};
int N[6];

int calc(int v) {
  int ans = 0;
  for (int i = 5; i >= 0; i--) {
    ans += v / C[i];
    v %= C[i];
  }
  return ans;
}

int main() {
  int P;
  while (cin >> P) {
    if (P == 0)
      break;
    for (int i = 0; i < 6; i++)
      cin >> N[i];

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

    vector<vector<int>> dp(2, vector<int>(T, 1001001001));
    dp[0][0] = 0;

    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < C[i]; j++) {
        deque<pair<int, int>> deq;
        for (int k = j; k < T; k += C[i]) {
          int w = T - k / C[i];
          dp[(i + 1) % 2][k] = min(dp[(i + 1) % 2][k], dp[i % 2][k]);
          while (!deq.empty() && deq.front().second + C[i] * N[i] < k)
            deq.pop_front();
          if (!deq.empty())
            dp[(i + 1) % 2][k] = min(dp[(i + 1) % 2][k], deq.front().first - w);
          if (!deq.empty() && deq.front().second + N[i] * C[i] <= k)
            deq.pop_front();
          deq.push_back(make_pair(dp[i % 2][k] + w, k));
        }
      }
    }

    int mi = 1001001001;
    int prev = 1001001001;
    for (int i = calc(P); i < T; i++) {
      prev = min(prev, dp[0][i] + calc(i - P));
      mi = min(mi, prev);
    }

    cout << mi + cnt << endl;
  }

  return 0;
}