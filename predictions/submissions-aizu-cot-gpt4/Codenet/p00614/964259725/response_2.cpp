#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <algorithm>

typedef long long ll;

const ll T = 10000;
const ll INF = 1001001001;
std::array<ll, 6> C = {1, 5, 10, 50, 100, 500};
std::array<ll, 6> N;
std::array<std::array<ll, T>, 2> dp;

ll calc(ll v) {
  ll ans = 0;
  for (int i = 5; i >= 0; i--) {
    ans += v / C[i];
    v %= C[i];
  }
  return ans;
}

int main() {
  ll P;
  while (std::cin >> P) {
    if (P == 0)
      break;
    for (auto &n : N) std::cin >> n;
    std::fill(dp[0].begin(), dp[0].end(), INF);
    std::fill(dp[1].begin(), dp[1].end(), INF);
    dp[0][0] = 0;
    ll cnt = 0;
    for (int i = 5; i >= 0; i--) {
      while (P - C[i] >= 2500 && N[i]) {
        cnt++;
        N[i]--;
        P -= C[i];
      }
    }
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < C[i]; j++) {
        std::deque<std::pair<ll, ll>> deq;
        for (ll k = j; k < T; k += C[i]) {
          ll w = T - k / C[i];
          while (deq.size() && deq.front().second + C[i] * N[i] < k)
            deq.pop_front();
          if (deq.size())
            dp[(i + 1) & 1][k] = std::min(dp[(i + 1) & 1][k], deq.front().first - w);
          if (deq.size() && deq.front().second + N[i] * C[i] <= k)
            deq.pop_front();
          deq.push_back(std::make_pair(dp[i & 1][k] + w, k));
        }
      }
    }
    ll mi = INF;
    for (ll i = P; i < T; i++) {
      mi = std::min(mi, dp[0][i] + calc(i - P));
    }
    std::cout << mi + cnt << std::endl;
  }
  return 0;
}