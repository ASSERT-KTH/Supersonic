#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

vector<P> book;
int solve() {
  int sumf = 0, sums = 0;
  for (int i = 0; i < book.size(); i++)
    sumf += book[i].first, sums += book[i].second;
  if (2 * book[0].first <= sumf)
    return sumf + sums;
  int d = 2 * book[0].first - sumf, dp[3000] = {1}, D = d;
  for (int i = 1; i < book.size(); i++)
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
    sort(book.begin(), book.end(), greater<P>());
    cout << solve() << endl;
  }
  return 0;
}