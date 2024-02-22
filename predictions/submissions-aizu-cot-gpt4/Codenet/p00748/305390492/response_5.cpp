#include <algorithm>
#include <iostream>
#define INF 1 << 28
using namespace std;
int p[1000001];
int memo[1000001][6];
int memo2[1000001];

void precompute() {
  for (int i = 0; i <= 1000000; i++)
    p[i] = i * (i + 1) * (i + 2) / 6;
}

void initialize_memo() {
  for (int i = 0; i <= 1000000; i++) {
    memo[i][0] = INF;
    if (i != 0) memo[0][i] = INF;
    else memo[0][i] = 0;
    memo2[i] = (i == 0) ? 0 : INF;
  }
}

int solve(int n, int count) {
  if (memo[n][count] != INF)
    return memo[n][count];
  for (int i = 0; p[i] <= n; i++)
    memo[n][count] = min(memo[n][count], solve(n - p[i], count - 1) + 1);
  return memo[n][count];
}

int solve2(int n) {
  if (memo2[n] != INF)
    return memo2[n];
  for (int i = 0; p[i] <= n; i+=2) {
    memo2[n] = min(memo2[n], solve2(n - p[i]) + 1);
  }
  return memo2[n];
}

int main() {
  precompute();
  initialize_memo();
  int n;
  while (cin >> n, n)
    cout << solve(n, 5) << " " << solve2(n) << endl;
}