#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int, int>;
using vpint = vector<pint>;

const int MAX_C = 6;
const int INF = 1001001001;
const int MAX_T = 10000;
const int MAX_N = 10000;

int C[MAX_C] = {1, 5, 10, 50, 100, 500};
int P;
int N[MAX_C];
int dp[2][MAX_T];

int calc(int v) {
  int ans = 0;
  for (int i = 5; i >= 0; i--) {
    ans += v / C[i];
    v %= C[i];
  }
  return ans;
}

signed main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  while (cin >> P) {
    for (int i = 0; i < MAX_C; i++) {
      cin >> N[i];
    }
    if (P == 0) {
      break;
    }

    fill_n(*dp, 2 * MAX_T, INF);
    int cnt = 0;
    for (int i = 5; i >= 0; i--) {
      while (P - C[i] >= 2500 && N[i] > 0) {
        cnt++;
        N[i]--;
        P -= C[i];
      }
      if (N[i] > 0) {
        break;
      }
    }
    dp[0][0] = 0;
    for (int i = 0; i < MAX_C; i++) {
      int cur = i & 1, nxt = (i + 1) & 1;
      for (int j = 0; j < C[i]; j++) {
        deque<pint> deq;
        for (int k = j; k < MAX_T; k += C[i]) {
          int w = MAX_T - k / C[i];
          dp[nxt][k] = min(dp[nxt][k], dp[cur][k]);
          while (!deq.empty() && deq.front().second + C[i] * N[i] < k) {
            deq.pop_front();
          }
          if (!deq.empty()) {
            dp[nxt][k] = min(dp[nxt][k], deq.front().first - w);
          }
          if (!deq.empty() && deq.front().second + N[i] * C[i] <= k) {
            deq.pop_front();
          }
          deq.emplace_back(dp[cur][k] + w, k);
        }
      }
    }
    int mi = INF;
    for (int i = P; i < MAX_T; i++) {
      mi = min(mi, dp[0][i] + calc(i - P));
    }
    cout << mi + cnt << '\n';
  }

  return 0;
}
