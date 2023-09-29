#include <bits/stdc++.h>
using namespace std;
int n;
int solve() {
  int sumf = 0, sums = 0;
  int f, s;
  for (int i = 0; i < n; i++){
    cin >> f >> s;
    sumf += f, sums += s;
  }
  if (2 * f <= sumf)
    return sumf + sums;
  int d = 2 * f - sumf, dp[3001] = {1}, D = d;
  for (int i = 0; i < n; i++)
    for (int j = d - cin >> s, cin >> f, s; j >= 0; j--)
      dp[j + s] |= dp[j];
  while (!dp[D])
    D--;
  return sumf + sums + (d - D);
}
int main() {
  while (cin >> n, n) {
    cout << solve() << endl;
  }
  return 0;
}