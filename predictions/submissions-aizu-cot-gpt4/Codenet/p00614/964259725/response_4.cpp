#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const ll T = 10000;
ll C[6] = {1, 5, 10, 50, 100, 500};
ll P;
ll N[6];
ll dp[2][T];

ll calc(ll v) {
  ll ans = 0;
  for (ll i = 5; i >= 0; i--) {
    ans += v / C[i];
    v %= C[i];
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  while (cin >> P) {
    for(ll i = 0; i < 6; i++) 
      cin >> N[i];
    if (P == 0)
      break;
    fill_n(*dp, 2 * T, 1001001001);
    ll cnt = 0;
    for (ll i = 5; i >= 0; i--) {
      while (P - C[i] >= 2500 && N[i]) {
        cnt++;
        N[i]--;
        P -= C[i];
      }
      if (N[i])
        break;
    }
    dp[0][0] = 0;
    for(ll i = 0; i < 6; i++) {
      for(ll j = 0; j < C[i]; j++) {
        queue<pll> deq;
        for (ll k = j; k < T; k += C[i]) {
          ll w = T - k / C[i];
          dp[(i + 1) & 1][k % T] = min(dp[(i + 1) & 1][k % T], dp[i & 1][k % T]);
          while (!deq.empty() && deq.front().second + C[i] * N[i] < k)
            deq.pop();
          if (!deq.empty())
            dp[(i + 1) & 1][k % T] = min(dp[(i + 1) & 1][k % T], deq.front().first - w);
          if (!deq.empty() && deq.front().second + N[i] * C[i] <= k)
            deq.pop();
          deq.push(pll(dp[i & 1][k % T] + w, k));
        }
      }
    }
    ll mi = 1001001001;
    for (ll i = P; i < T; i++) {
      mi = min(mi, dp[0][i % T] + calc(i - P));
    }
    cout << mi + cnt << "\n";
  }
  return 0;
}