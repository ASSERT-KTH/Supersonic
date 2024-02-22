#include <iostream>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::vector;
using std::greater;

typedef pair<int, int> Pair;
vector<Pair> book;
int dp[3000] = {1};

int solve(int n) {
  int sumf = 0, sums = 0;
  for (int i = 0; i < n; i++)
    sumf += book[i].first, sums += book[i].second;
  if (2 * book[0].first <= sumf)
    return sumf + sums;
  int d = 2 * book[0].first - sumf, D = d;
  for (int i = 1; i < n; i++)
    for (int j = d - book[i].second; j >= 0; j--)
      dp[j + book[i].second] |= dp[j];
  while (!dp[D])
    D--;
  return sumf + sums + (d - D);
}

int main() {
  int n;
  while (cin >> n, n) {
    book.resize(n);
    for (int i = 0; i < n; i++)
      cin >> book[i].first >> book[i].second;
    sort(book.begin(), book.end(), greater<Pair>());
    cout << solve(n) << endl;
  }
  return 0;
}