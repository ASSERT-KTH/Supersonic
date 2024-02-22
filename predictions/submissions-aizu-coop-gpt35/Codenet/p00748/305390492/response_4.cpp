#include <algorithm>
#include <iostream>
#include <vector>
#define INF 1 << 28
using namespace std;

vector<int> p;
vector<vector<int>> memo;
vector<int> memo2;

int solve(int n, int count) {
  if (n <= 0 || count == 0)
    return INF;
  if (memo[n][count])
    return memo[n][count];
  int ans = INF;
  for (int i = p.size() - 1; i >= 0; i--) {
    int term = p[i];
    if (term <= n)
      ans = min(ans, solve(n - term, count - 1) + 1);
  }
  return memo[n][count] = ans;
}

int solve2(int n) {
  if (n == 0)
    return 0;
  if (memo2[n])
    return memo2[n];
  int ans = INF;
  for (int i = p.size() - 1; i >= 0; i--) {
    int term = p[i];
    if (term <= n && term % 2 == 1)
      ans = min(ans, solve2(n - term) + 1);
  }
  return memo2[n] = ans;
}

int main() {
  int n;
  for (int i = 0; i <= 1000000; i++)
    p.push_back(i * (i + 1) * (i + 2) / 6);
  memo.resize(1000001, vector<int>(6, 0));
  memo2.resize(1000001, 0);
  for (int i = 1; i <= 1000000; i++)
    solve2(i);
  while (cin >> n, n) {
    cout << solve(n, 5) << " " << solve2(n) << endl;
  }
  return 0;
}