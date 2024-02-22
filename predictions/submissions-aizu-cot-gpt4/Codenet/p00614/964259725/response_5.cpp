#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;
using vint = vector<int>;
using pint = pair<int, int>;
using vpint = vector<pint>;
constexpr int T = 10000;

int calc(int v, const vint& C) {
  int ans = 0;
  for (int i = 5; i >= 0; i--) {
    ans += v / C[i];
    v %= C[i];
  }
  return ans;
}

int main() {
  int C[6] = {1, 5, 10, 50, 100, 500};
  int P;
  int N[6];
  int dp[2][T];
  while (cin >> P) {
    for(int i = 0; i < 6; i++) cin >> N[i];
    if (P == 0)
      break;
    fill_n(*dp, 2 * T, INT_MAX);
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
    dp[0][0] = 0;
    for(int i = 0; i < 6; i++) {
      for(int j = 0; j < C[i]; j++) {
        priority_queue<pint> pq;
        for (int k = j; k < T; k += C[i]) {
          int w = T - k / C[i];
          dp[(i + 1) & 1][k] = min(dp[(i + 1) & 1][k], dp[i & 1][k]);
          while (!pq.empty() && pq.top().second + C[i] * N[i] < k)
            pq.pop();
          if (!pq.empty())
            dp[(i + 1) & 1][k] = min(dp[(i + 1) & 1][k], pq.top().first - w);
          if (!pq.empty() && pq.top().second + N[i] * C[i] <= k)
            pq.pop();
          pq.push(pint(dp[i & 1][k] + w, k));
        }
      }
    }
    int mi = INT_MAX;
    for (int i = P; i < T; i++) {
      mi = min(mi, dp[0][i] + calc(i - P, C));
    }
    cout << mi + cnt << '\n';
  }
  return 0;
}