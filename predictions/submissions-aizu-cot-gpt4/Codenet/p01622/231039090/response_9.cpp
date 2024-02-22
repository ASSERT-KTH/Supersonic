#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int, int> P;
int n;
P book[1001];
int solve(int sumf, int sums) {
  if (2 * book[0].f <= sumf)
    return sumf + sums;
  int d = 2 * book[0].f - sumf;
  vector<int> dp(d + 1, 0);
  dp[0] = 1;
  for (int i = 1; i < n; i++)
    for (int j = min(d, d - book[i].s); j >= 0; j--)
      dp[min(j + book[i].s, d)] |= dp[j];
  while (!dp[d])
    d--;
  return sumf + sums + d;
}
int main() {
  while (cin >> n, n) {
    int sumf = 0, sums = 0;
    for (int i = 0; i < n; i++) {
      cin >> book[i].f >> book[i].s;
      sumf += book[i].f; 
      sums += book[i].s;
    }
    sort(book, book + n, greater<P>());
    cout << solve(sumf, sums) << endl;
  }
  return 0;
}