#include <algorithm>
#include <iostream>
#define INF 1 << 28
using namespace std;
int p[1000001];
int memo[1000001][6];
int memo2[1000001];

int solve(int n, int count) {
  if (n == 0)
    return 0;
  if (n <= 0 || count == 0)
    return INF;
  
  if (memo[n][count] != 0)
    return memo[n][count];
  
  int ans = INF;
  for (int i = 0; p[i] <= n && p[i] != 0; i++)
    ans = min(ans, solve(n - p[i], count - 1) + 1);
  
  return memo[n][count] = ans;
}

int solve2(int n) {
  if (n == 0)
    return 0;
  if (n < 0)
    return INF;
  
  if (memo2[n] != 0)
    return memo2[n];
  
  int ans = INF;
  for (int i = 0; p[i] <= n && p[i] != 0; i++) {
    if (p[i] % 2 == 0)
      continue;
    ans = min(ans, solve2(n - p[i]) + 1);
  }
  
  return memo2[n] = ans;
}

int main() {
  for (int i = 0; i <= 1000000; i++) {
    p[i] = i * (i + 1) * (i + 2) / 6;
    if (i != 0)
      solve2(i);
  }

  int n;
  while (cin >> n, n)
    cout << solve(n, 5) << " " << solve2(n) << endl;
}