#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
constexpr ll C[6] = {1, 5, 10, 50, 100, 500};
ll P;
ll N[6];
constexpr ll T = 10000;
ll dp[2][T];

ll calc(ll v) {
  ll ans = 0;
  for (int i = 5; i >= 0; --i) {
    ans += v / C[i];
    v %= C[i];
  }
  return ans;
}

int main() {
  while (true) {
    cin >> P;
    if (P == 0)
      break;
    for(ll &i : N) cin >> i;
    fill_n(*dp, 2 * T, numeric_limits<ll>::max());
    ll cnt = 0;
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
    for (ll i = 0; i < 6; i++) {
      for (ll j = 0; j < C[i]; j++) {
        deque<pll> deq;
        for (ll k = j; k < T; k += C[i]) {
          ll w = T - k / C[i];
          dp[(i + 1) & 1][k] = min(dp[(i + 1) & 1][k], dp[i & 1][k]);
          while (!deq.empty() && deq.front().second + C[i] * N[i] < k)
            deq.pop_front();
          if (!deq.empty())
            dp[(i + 1) & 1][k] = min(dp[(i + 1) & 1][k], deq.front().first - w);
          if (!deq.empty() && deq.front().second + N[i] * C[i] <= k)
            deq.pop_front();
          deq.push_back({dp[i & 1][k] + w, k});
        }
      }
    }
    ll mi = *min_element(dp[0] + P, dp[0] + T, [](ll a, ll b) { return a + calc(a - P) < b + calc(b - P); });
    cout << mi + cnt << "\n";
  }
  return 0;
}