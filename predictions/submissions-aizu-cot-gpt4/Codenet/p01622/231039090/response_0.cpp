#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

using P = pair<int, int>;

int solve(int n, vector<P>& book) {
  int sumf = 0, sums = 0;
  for (int i = 0; i < n; i++)
    sumf += book[i].first, sums += book[i].second;

  if (2 * book[0].first <= sumf)
    return sumf + sums;

  int d = 2 * book[0].first - sumf, dp[3000] = {1}, D = d;
  for (int i = 1; i < n; i++)
    for (int j = d - book[i].second; j >= 0; j--)
      dp[j + book[i].second] |= dp[j];

  for (; D >= 0 && !dp[D]; --D);
  
  return sumf + sums + (d - D);
}

int main() {
  int n;
  while (cin >> n, n) {
    vector<P> book(n);
    for (int i = 0; i < n; i++)
      cin >> book[i].first >> book[i].second;
    sort(book.begin(), book.end(), greater<P>());
    cout << solve(n, book) << endl;
  }
  return 0;
}