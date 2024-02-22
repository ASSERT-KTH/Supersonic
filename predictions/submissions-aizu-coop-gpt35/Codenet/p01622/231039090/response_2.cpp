#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

typedef std::pair<int, int> P;

int solve(const std::vector<P>& book, int d) {
  int sumf = std::accumulate(book.begin(), book.end(), 0, [](int a, const P& b){ return a + b.first; });
  int sums = std::accumulate(book.begin(), book.end(), 0, [](int a, const P& b){ return a + b.second; });

  if (2 * book[0].first <= sumf)
    return sumf + sums;

  std::vector<bool> dp(d + 1, false);
  dp[0] = true;

  for (size_t i = 1; i < book.size(); i++) {
    for (int j = d; j >= book[i].second; j--) {
      dp[j] |= dp[j - book[i].second];
    }
  }

  auto it = std::find(dp.rbegin(), dp.rend(), true);
  int D = std::distance(dp.rbegin(), it);

  return sumf + sums + (d - D);
}

int main() {
  int n;
  while (std::cin >> n, n) {
    std::vector<P> book(n);
    for (int i = 0; i < n; i++) {
      std::cin >> book[i].first >> book[i].second;
    }

    int sumf = std::accumulate(book.begin(), book.end(), 0, [](int a, const P& b){ return a + b.first; });
    int sums = std::accumulate(book.begin(), book.end(), 0, [](int a, const P& b){ return a + b.second; });

    if (2 * book[0].first <= sumf) {
      std::cout << sumf + sums << std::endl;
      continue;
    }

    bool sorted = true;
    for (size_t i = 0; i < book.size() - 1; i++) {
      if (book[i].first > book[i + 1].first) {
        sorted = false;
        break;
      }
    }

    if (!sorted) {
      std::sort(book.begin(), book.end(), std::greater<P>());
    }

    int d = 2 * book[0].first - sumf;
    std::cout << solve(book, d) << std::endl;
  }

  return 0;
}