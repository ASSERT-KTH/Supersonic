#include <iostream>
#include <vector>
#include <algorithm>
typedef std::pair<int, int> Pair;

int solve(std::vector<Pair>& books, int n) {
  int sumf = 0, sums = 0;
  for (int i = 0; i < n; i++)
    sumf += books[i].first, sums += books[i].second;
  if (2 * books[0].first <= sumf)
    return sumf + sums;
  int d = 2 * books[0].first - sumf, D = d;
  std::vector<int> dp(3000, 0);
  dp[0] = 1;
  for (int i = 1; i < n; i++)
    for (int j = d - books[i].second; j >= 0; j--)
      dp[j + books[i].second] |= dp[j];
  while (!dp[D])
    D--;
  return sumf + sums + (d - D);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int n;
  while (std::cin >> n, n) {
    std::vector<Pair> books(n);
    for (int i = 0; i < n; i++)
      std::cin >> books[i].first >> books[i].second;
    sort(books.begin(), books.end(), std::greater<Pair>());
    std::cout << solve(books, n) << std::endl;
  }
  return 0;
}