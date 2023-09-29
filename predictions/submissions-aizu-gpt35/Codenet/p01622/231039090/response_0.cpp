#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int, int> P;
int n;
P book[1001];
int solve() {
  int sumf = 0, sums = 0, maxf = 0;
  for (int i = 0; i < n; i++) {
    sumf += book[i].f, sums += book[i].s;
    maxf = max(maxf, book[i].f);
  }
  if (2 * maxf <= sumf)
    return sumf + sums;
  int d = 2 * maxf - sumf, dp[3001] = {1}, D = d;
  for (int i = 0; i < n; i++) {
    if (book[i].f >= maxf)
      break;
    for (int j = d - book[i].s; j >= 0; j--)
      dp[j + book[i].s] |= dp[j];
  }
  while (!dp[D])
    D--;
  return sumf + sums + (d - D);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  while (cin >> n, n) {
    for (int i = 0; i < n; i++)
      cin >> book[i].f >> book[i].s;
    sort(book, book + n, greater<P>());
    cout << solve() << "\n";
  }
  return 0;
}