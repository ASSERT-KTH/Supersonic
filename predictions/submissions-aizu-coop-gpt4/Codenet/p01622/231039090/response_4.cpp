#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int, int> P;
int n;
P book[1001];
int dp[3000];

int solve() {
  memset(dp, 0, sizeof(dp));  // Clear the dp array
  dp[0] = 1;  // Set the first element to 1
  int sumf = 0, sums = 0;
  for (int i = 0; i < n; i++)
    sumf += book[i].f, sums += book[i].s;
  if (2 * book[0].f <= sumf)
    return sumf + sums;
  int d = 2 * book[0].f - sumf, D = d;
  for (int i = 1; i < n; i++)
    for (int j = min(d, sumf) - book[i].s; j >= 0; j--)  // Start from min(d, sumf) - book[i].s
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