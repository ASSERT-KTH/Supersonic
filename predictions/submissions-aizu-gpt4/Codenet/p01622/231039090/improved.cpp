#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int, int> P;
int n;
P book[1001];
int solve() {
  int sumf = 0, sums = 0;
  for (int i = 0; i < n; i++)
    sumf += book[i].f, sums += book[i].s;
  int d = max(0, 2 * book[0].f - sumf), dp[3000] = {1};
  for (int i = 1; i < n; i++)
    for (int j = d - book[i].s; j >= 0; j--)
      dp[j + book[i].s] |= dp[j];
  int cnt = 0;
  while (!dp[d--])
    cnt++;
  return sumf + sums + cnt;
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
