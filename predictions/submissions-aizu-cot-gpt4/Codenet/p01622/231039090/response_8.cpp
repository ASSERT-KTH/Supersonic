#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;

int n;
vector<P> book;
int solve() {
  int sumf = 0, sums = 0;
  for (int i = 0; i < n; i++)
    sumf += book[i].first, sums += book[i].second;
  int d = 2 * book[0].first - sumf;
  if (d <= 0)
    return sumf + sums;
  vector<int> dp(d+1, 0);
  dp[0] = 1;
  for (int i = 1; i < n; i++)
    for (int j = d - book[i].second; j >= 0; j--)
      dp[j + book[i].second] |= dp[j];
  while (!dp[d])
    d--;
  return sumf + sums + d;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  while (cin >> n, n) {
    book.resize(n);
    for (int i = 0; i < n; i++)
      cin >> book[i].first >> book[i].second;
    sort(book.rbegin(), book.rend());
    cout << solve() << "\n";
  }
  return 0;
}