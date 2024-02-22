#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::max;
using std::memset;
using std::min;
using std::pair;
using std::string;

typedef long long ll;
typedef pair<int, int> pint;

const double PI = acos(-1.0);
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int n, m;

int dpru(int* c, int** v) {
  int** dp = new int*[n + 1];
  for (int i = 0; i <= n; ++i) {
    dp[i] = new int[m + 1];
    memset(dp[i], 0, (m + 1) * sizeof(int));
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= m; ++j) {
      dp[i + 1][j] = dp[i][j];
      if (j >= c[i])
        max_swap(dp[i + 1][j], dp[i + 1][j - c[i]] + v[i][j]);
    }
  }

  int res = dp[n][m];

  for (int i = 0; i <= n; ++i) {
    delete[] dp[i];
  }
  delete[] dp;

  return res;
}

int main() {
  while (cin >> n >> m) {
    int c[333], v[3][333];
    for (int i = 0; i < n; ++i) {
      int t;
      cin >> t;
      c[i] = t;
      for (int j = 0; j < 3; ++j) {
        cin >> v[j][i];
      }
    }
    int res = 0;
    for (int i = 0; i < 3; ++i)
      max_swap(res, dpru(c, v));
    cout << res << endl;
  }
}