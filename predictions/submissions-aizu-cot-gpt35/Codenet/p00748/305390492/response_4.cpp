#include <iostream>
#include <vector>
using namespace std;

vector<int> p;
vector<vector<int>> memo;
vector<int> memo2;

int solve(int n, int count) {
  if (!n)
    return 0;
  if (n <= 0 || !count)
    return INT_MAX;
  if (memo[n][count])
    return memo[n][count];
  int ans = INT_MAX;
  int low = 0, high = p.size() - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (p[mid] == n) {
      ans = min(ans, solve(n - p[mid], count - 1) + 1);
      break;
    } else if (p[mid] < n) {
      ans = min(ans, solve(n - p[mid], count - 1) + 1);
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return memo[n][count] = ans;
}

int solve2(int n) {
  if (!n)
    return 0;
  if (n < 0)
    return INT_MAX;
  if (memo2[n])
    return memo2[n];
  int ans = INT_MAX;
  if (n % 2 == 1) {
    for (int i = 0; p[i] <= n; i++) {
      ans = min(ans, solve2(n - p[i]) + 1);
    }
  }
  return memo2[n] = ans;
}

int main() {
  int n;
  for (int i = 0; p[i] <= 1000000; i++)
    p.push_back(i * (i + 1) * (i + 2) / 6);
  memo.resize(1000001, vector<int>(6));
  memo2.resize(1000001);
  for (int i = 1; i <= 1000000; i++)
    solve2(i);
  while (cin >> n, n)
    cout << solve(n, 5) << " " << solve2(n) << endl;
}