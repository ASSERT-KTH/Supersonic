#include <iostream>
#include <vector>
#include <utility>

#define int long long
typedef vector<int> vint;
typedef pair<int, int> pint;
typedef vector<pint> vpint;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, f, n) for (int i = (f); i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define fi first
#define se second

constexpr int C[6] = {1, 5, 10, 50, 100, 500};
int P;
constexpr int N[6];
constexpr int T = 10000;
int dp[2][T];

int calc(int v) {
  int ans = 0;
  for (int i = 5; i >= 0; i--) {
    ans += v / C[i];
    v %= C[i];
  }
  return ans;
}

signed main() {
  while (std::cin >> P) {
    rep(i, 6) std::cin >> N[i];
    if (P == 0)
      break;
    std::fill_n(*dp, 2 * T, 1001001001);
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
        vector<pint> deq;
        for (int k = j; k < T; k += C[i]) {
          int w = T - k / C[i];
          dp[(i + 1) & 1][k] = min(dp[(i + 1) & 1][k], dp[i & 1][k]);
          while (!deq.empty() && deq.front().se + C[i] * N[i] < k)
            deq.erase(deq.begin());
          if (!deq.empty())
            dp[(i + 1) & 1][k] = min(dp[(i + 1) & 1][k], deq.front().fi - w);
          deq.pb(pint(dp[i & 1][k] + w, k));
        }
      }
    }
    int mi = 1001001001;
    for (int i = P; i < T; i++) {
      mi = min(mi, dp[0][i] + calc(i - P));
    }
    std::cout << mi + cnt << std::endl;
  }
  return 0;
}