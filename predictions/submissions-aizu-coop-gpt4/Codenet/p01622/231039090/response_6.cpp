#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
int n;
P book[1001];

int solve() {
  int sumf = 0, sums = 0;
  if (2 * book[0].first <= sumf)
    return sumf + sums;
  int d = 2 * book[0].first - sumf, dp[3000] = {1}, D = d;
  for (int i = 1; i < n; i++)
    for (int j = d; j >= book[i].second; j--)
      dp[j] |= dp[j - book[i].second];
  while (!dp[D])
    D--;
  return sumf + sums + (d - D);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while (cin >> n, n) {
    int sumf = 0, sums = 0;
    for (int i = 0; i < n; i++) {
      cin >> book[i].first >> book[i].second;
      sumf += book[i].first;
      sums += book[i].second;
    }
    sort(book, book + n, greater<P>());
    cout << solve() << endl;
  }
  return 0;
}