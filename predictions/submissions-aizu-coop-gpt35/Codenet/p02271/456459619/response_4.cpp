#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

bool solve(int i, int m, int n, int N[], bool dp[][10001]) {
  if (i == n) {
    return m == 0 ? true : false;
  }
  if (dp[i][m]) {
    return dp[i][m];
  }
  bool result = solve(i + 1, m - N[i], n, N, dp) || solve(i + 1, m, n, N, dp);
  dp[i][m] = result;
  return result;
}

int main() {
  #pragma GCC optimize ("O3")

  int n;
  scanf("%d", &n);
  int N[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &N[i]);
  }

  int t;
  scanf("%d", &t);
  
  bool dp[n][10001];
  memset(dp, false, sizeof(dp));

  for (int i = 0; i < t; i++) {
    int p;
    scanf("%d", &p);
    if (solve(0, p, n, N, dp)) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
}