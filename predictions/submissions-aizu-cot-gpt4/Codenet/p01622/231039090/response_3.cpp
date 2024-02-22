#include <iostream>
#include <algorithm>

#define f first
#define s second

std::pair<int, int> *book;
int dp[3000] = {1};
int n;

int solve() {
  int sumf = 0, sums = 0;
  for (int i = 0; i < n; i++)
    sumf += book[i].f, sums += book[i].s;
  if (2 * book[0].f <= sumf)
    return sumf + sums;
  int d = 2 * book[0].f - sumf, D = d;
  for (int i = 1; i < n; i++)
    for (int j = d - book[i].s; j >= 0; j--)
      dp[j + book[i].s] |= dp[j];
  while (!dp[D])
    D--;
  return sumf + sums + (d - D);
}

int main() {
  while (std::cin >> n, n) {
    book = new std::pair<int, int>[n];
    for (int i = 0; i < n; i++)
      std::cin >> book[i].f >> book[i].s;
    std::sort(book, book + n, std::greater<std::pair<int, int>>());
    std::cout << solve() << std::endl;
    delete[] book;
  }
  return 0;
}