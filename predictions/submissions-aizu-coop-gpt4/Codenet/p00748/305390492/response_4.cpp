#include <algorithm>
#include <iostream>
#include <vector>
#define INF 1 << 28
using namespace std;
vector<int> p(1000001);
vector<vector<int>> memo(1000001, vector<int>(6, INF));
vector<int> memo2(1000001, INF);

void solve() {
  memo[0][0] = 0;
  for (int count = 1; count <= 5; count++) {
    for (int n = 1; n <= 1000000; n++) {
      for (int i = 0; p[i] <= n; i++) {
        memo[n][count] = min(memo[n][count], memo[n - p[i]][count - 1] + 1);
      }
    }
  }
}

void solve2() {
  memo2[0] = 0;
  for (int n = 1; n <= 1000000; n++) {
    for (int i = 0; p[i] <= n; i++) {
      if (p[i] % 2)
        memo2[n] = min(memo2[n], memo2[n - p[i]] + 1);
    }
  }
}

int main() {
  for (int i = 0; i <= 1000000; i++)
    p[i] = i * (i + 1) * (i + 2) / 6;
  solve();
  solve2();
  int n;
  while (cin >> n, n)
    cout << memo[n][5] << " " << memo2[n] << endl;
}