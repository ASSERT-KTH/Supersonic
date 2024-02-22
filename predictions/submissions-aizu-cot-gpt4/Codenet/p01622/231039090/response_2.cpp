#include <iostream>
#include <vector>
#include <algorithm>

typedef std::pair<int, int> P;

int solve(std::vector<P>& book, int n) {
  int sumf = std::accumulate(book.begin(), book.end(), 0, [](int sum, const P& p){return sum+p.first;});
  int sums = std::accumulate(book.begin(), book.end(), 0, [](int sum, const P& p){return sum+p.second;});

  if (2 * book[0].first <= sumf)
    return sumf + sums;

  int d = 2 * book[0].first - sumf;
  std::vector<int> dp(3000, 0);
  dp[0] = 1;
  int D = d;
  
  for (int i = 1; i < n; i++)
    for (int j = d - book[i].second; j >= 0; j--)
      dp[j + book[i].second] |= dp[j];
  while (!dp[D])
    D--;
  return sumf + sums + (d - D);
}

int main() {
  int n;
  while (std::cin >> n, n) {
    std::vector<P> book(n);
    for (int i = 0; i < n; i++)
      std::cin >> book[i].first >> book[i].second;
    std::sort(book.begin(), book.end(), std::greater<P>());
    std::cout << solve(book, n) << std::endl;
  }
  return 0;
}