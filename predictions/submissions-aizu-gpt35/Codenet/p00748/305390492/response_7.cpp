#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 1000000;
const int MAX_COUNT = 6;
const int INF = 1 << 28;

int p[MAX_N + 1];
int memo[MAX_N + 1][MAX_COUNT + 1];
int memo2[MAX_N + 1];

int solve(int n, int count) {
  if (n == 0) return 0;
  if (n < 0 || count == 0) return INF;
  if (memo[n][count]) return memo[n][count];
  int ans = INF;
  for (int i = 1; p[i] <= n; i++) {
    ans = min(ans, solve(n - p[i], count - 1) + 1);
  }
  return memo[n][count] = ans;
}

int solve2(int n) {
  if (n == 0) return 0;
  if (n < 0) return INF;
  if (memo2[n]) return memo2[n];
  int ans = INF;
  for (int i = 1; p[i] <= n; i++) {
    if (p[i] % 2 == 0) continue;
    ans = min(ans, solve2(n - p[i]) + 1);
  }
  return memo2[n] = ans;
}

int main() {
  for (int i = 1; i <= MAX_N; i++) {
    p[i] = i * (i + 1) * (i + 2) / 6;
  }
  for (int i = 1; i <= MAX_N; i++) {
    solve2(i);
  }
  int n;
  while (cin >> n, n) {
    cout << solve(n, MAX_COUNT) << " " << solve2(n) << endl;
  }
  return 0;
}