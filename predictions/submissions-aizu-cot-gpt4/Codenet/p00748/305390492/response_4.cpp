#include <algorithm>
#include <iostream>
#define INF 1 << 28
using namespace std;
int p[1000001];
int memo[1000001][6];
int memo2[1000001];
int solve(int n, int count) {
  for (int j = 0; j <= count; j++)
    for (int i = 0; i <= n; i++)
      if (!i)
        memo[i][j] = 0;
      else if (i < 0 || !j)
        memo[i][j] = INF;
      else {
        memo[i][j] = INF;
        for (int k = 0; p[k] <= i; k++)
          memo[i][j] = min(memo[i][j], memo[i - p[k]][j - 1] + 1);
      }
  return memo[n][count];
}
int solve2(int n) {
  for (int i = 0; i <= n; i++)
    if (!i)
      memo2[i] = 0;
    else if (i < 0)
      memo2[i] = INF;
    else {
      memo2[i] = INF;
      for (int j = 0; p[j] <= i; j++)
        if (p[j] % 2)
          memo2[i] = min(memo2[i], memo2[i - p[j]] + 1);
    }
  return memo2[n];
}
int main() {
  int n;
  while (cin >> n, n) {
    for (int i = 0; i <= n; i++)
      p[i] = i * (i + 1) * (i + 2) / 6;
    cout << solve(n, 5) << " " << solve2(n) << endl;
  }
}