#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1 << 28;
vector<int> p;
vector<vector<int>> memo;
vector<int> memo2;

int solve(int n, int count) {
  if(n == 0) return 0;
  if(n <= 0 || count == 0) return INF;
  if(memo[n][count] != -1) return memo[n][count];
  int ans = INF;
  for(int i = 0; p[i] <= n; i++) {
    ans = min(ans, solve(n - p[i], count - 1) + 1);
  }
  return memo[n][count] = ans;
}

int solve2(int n) {
  if(n == 0) return 0;
  if(n < 0) return INF;
  if(memo2[n] != -1) return memo2[n];
  int ans = INF;
  for(int i = 0; p[i] <= n; i++) {
    if(p[i] % 2 == 0) continue;
    ans = min(ans, solve2(n - p[i]) + 1);
  }
  return memo2[n] = ans;
}

int main() {
  int n;
  p.resize(1000001);
  memo.assign(1000001, vector<int>(6, -1));
  memo2.assign(1000001, -1);

  for(int i = 0; i <= 1000000; i++)
    p[i] = i * (i + 1) * (i + 2) / 6;
  for(int i = 1; i <= 1000000; i++)
    solve2(i);
  while (cin >> n, n)
    cout << solve(n, 5) << " " << solve2(n) << endl;
}