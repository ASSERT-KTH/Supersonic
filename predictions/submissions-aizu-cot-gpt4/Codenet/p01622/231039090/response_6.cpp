#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int, int> P;
int n;
P book[1001];
int solve() {
  int sumf = accumulate(book, book + n, 0, [](int sum, const P& p){ return sum + p.f; });
  int sums = accumulate(book, book + n, 0, [](int sum, const P& p){ return sum + p.s; });
  if (2 * book[0].f <= sumf)
    return sumf + sums;
  int d = 2 * book[0].f - sumf, D = d;
  vector<int> dp(d + 1);
  fill(dp.begin(), dp.end(), 1);
  for (int i = 1; i < n; i++)
    for (int j = d - book[i].s; j >= 0; j--)
      dp[j + book[i].s] |= dp[j];
  while (!dp[D])
    D--;
  return sumf + sums + (d - D);
}
int main() {
  while (cin >> n, n) {
    for (int i = 0; i < n; i++)
      cin >> book[i].f >> book[i].s;
    sort(book, book + n, greater<P>());
    cout << solve() << endl;
  }
  return 0;
}