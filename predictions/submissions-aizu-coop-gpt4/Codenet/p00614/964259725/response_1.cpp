#include <bits/stdc++.h>
using namespace std;
#define int long long
using vint = vector<int>;
using pint = pair<int, int>;
using vpint = vector<pint>;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define fi first
#define se second
array<int, 6> C = {1, 5, 10, 50, 100, 500};
int P;
array<int, 6> N;
const int T = 10000;
array<array<int, T>, 2> dp;
int calc(int v) {
  int ans = 0;
  for (int i = 5; i >= 0; i--) {
    ans += v / C[i];
    v %= C[i];
  }
  return ans;
}
signed main() {
  while (cin >> P) {
    rep(i, 6) cin >> N[i];
    if (P == 0)
      break;
    fill(all(dp), 1001001001);
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
    rep(i, 6) {
      rep(j, C[i]) {
        deque<pint> deq;
        for (int k = j; k < T; k += C[i]) {
          int w = T - k / C[i];
          dp[(i + 1) & 1][k] = min(dp[(i + 1) & 1][k], dp[i & 1][k]);
          while (deq.size() && deq.front().se + C[i] * N[i] < k)
            deq.pop_front();
          if (deq.size())
            dp[(i + 1) & 1][k] = min(dp[(i + 1) & 1][k], deq.front().fi - w);
          while (deq.size() && deq.front().se + N[i] * C[i] <= k)
            deq.pop_front();
          deq.pb(pint(dp[i & 1][k] + w, k));
        }
      }
    }
    int mi = 1001001001;
    for (int i = P; i < T; i++) {
      mi = min(mi, dp[0][i] + calc(i - P));
    }
    cout << mi + cnt << endl;
  }
  return 0;
}