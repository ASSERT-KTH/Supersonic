#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <algorithm>

using vint = std::vector<int>;
using pint = std::pair<int, int>;

const std::array<int, 6> C = {1, 5, 10, 50, 100, 500};
int P;
std::array<int, 6> N;
const int T = 10000;
std::array<std::array<int, T>, 2> dp;

inline int calc(int v) {
  int ans = 0;
  for (int i = 5; i >= 0; --i) {
    auto div = std::div(v, C[i]);
    ans += div.quot;
    v = div.rem;
  }
  return ans;
}

int main() {
  while (std::cin >> P) {
    for (auto& val : N) std::cin >> val;
    if (P == 0) break;
    std::fill(dp[0].begin(), dp[0].end(), 1001001001);
    std::fill(dp[1].begin(), dp[1].end(), 1001001001);
    int cnt = 0;
    for (int i = 5; i >= 0; --i) {
      while (P - C[i] >= 2500 && N[i]) {
        ++cnt;
        --N[i];
        P -= C[i];
      }
      if (N[i]) break;
    }
    dp[0][0] = 0;
    std::deque<pint> deq;
    for (int i = 0; i < 6; ++i) {
      for (int j = 0; j < C[i]; ++j) {
        deq.clear();
        for (int k = j; k < T; k += C[i]) {
          int w = T - k / C[i];
          dp[(i + 1) & 1][k] = std::min(dp[i & 1][k], dp[(i + 1) & 1][k]);
          while (!deq.empty() && deq.front().second + C[i] * N[i] < k) 
            deq.pop_front();
          if (!deq.empty())
            dp[(i + 1) & 1][k] = std::min(dp[(i + 1) & 1][k], deq.front().first - w);
          deq.emplace_back(dp[i & 1][k] + w, k);
        }
      }
    }
    int mi = *std::min_element(dp[0].begin() + P, dp[0].end());
    std::cout << mi + cnt + calc(T - P) << std::endl;
  }
  return 0;
}