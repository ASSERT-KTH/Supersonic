#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

using ll = long long;
using vi = vector<ll>;
using pii = pair<ll, ll>;
using vpii = vector<pii>;

const int T = 10000;

ll C[6] = {1, 5, 10, 50, 100, 500};
ll P;
ll N[6];
ll dp[T];

ll calc(ll v) {
  ll ans = 0;
  for (int i = 5; i >= 0; i--) {
    ans += v / C[i];
    v %= C[i];
  }
  return ans;
}

int main() {
  while (cin >> P) {
    for (int i = 0; i < 6; i++) cin >> N[i];
    if (P == 0)
      break;
    fill(dp, dp + T, 1001001001);
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
    dp[0] = 0;
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < C[i]; j++) {
        deque<pii> deq;
        for (int k = j; k < T; k += C[i]) {
          ll w = T - k / C[i];
          if (deq.size() && deq.front().second + C[i] * N[i] < k)
            deq.pop_front();
          if (deq.size())
            dp[k] = min(dp[k], deq.front().first - w);
          if (deq.size() && deq.front().second + N[i] * C[i] <= k)
            deq.pop_front();
          deq.push_back(make_pair(dp[k] + w, k));
        }
      }
    }
    ll mi = 1001001001;
    for (int i = P; i < T; i++) {
      mi = min(mi, dp[i] + calc(i - P));
    }
    cout << mi + cnt << endl;
  }
  return 0;
}