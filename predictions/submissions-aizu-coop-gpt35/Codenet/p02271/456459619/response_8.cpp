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

vector<int> N;
int n;
vector<vector<bool>> dp;

bool solve(int i, int m) {
  if (dp[i][m] != -1) {
    return dp[i][m];
  }
  if (i == n) {
    return dp[i][m] = (m == 0);
  }
  return dp[i][m] = solve(i + 1, m - N[i]) || solve(i + 1, m);
}

int main() {
  int t;
  scanf("%d", &n);
  
  N.resize(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &N[i]);
  }
  
  scanf("%d", &t);
  
  dp.assign(n + 1, vector<bool>(t + 1, -1));
  
  for (int i = 0; i < t; i++) {
    int p;
    scanf("%d", &p);
    if (solve(0, p)) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
}