#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
#define int long long
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define fi first
#define se second
template <typename A, typename B> inline void chmin(A &a, B b) {
  if (a > b)
    a = b;
}
int C[6] = {1, 5, 10, 50, 100, 500};
int P;
int N[6];
const int T = 10000;
int dp[2][T];
int calc(int v) {
  int ans = 0;
  for_each(rbegin(C), rend(C), [&ans, &v](int c) {
    ans += v / c;
    v %= c;
  });
  return ans;
}
signed main() {
  while (cin >> P) {
    for(auto &n: N) cin >> n;
    if (P == 0)
      break;
    fill_n(*dp, 2 * T, 1001001001);
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
    for(auto &c: C) {
      for(int j = 0; j < c; j++) {
        deque<pair<int, int>> deq;
        for (int k = j; k < T; k += c) {
          int w = T - k / c;
          chmin(dp[(i + 1) & 1][k], dp[i & 1][k]);
          while (deq.size() && deq.front().se + c * N[i] < k)
            deq.pop_front();
          if (deq.size())
            chmin(dp[(i + 1) & 1][k], deq.front().fi - w);
          deq.pb(pair<int, int>(dp[i & 1][k] + w, k));
        }
      }
    }
    int mi = 1001001001;
    for (int i = P; i < T; i++) {
      chmin(mi, dp[0][i] + calc(i - P));
    }
    cout << mi + cnt << endl;
  }
  return 0;
}