#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <cmath>
#include <cassert>
#include <cstdio>
using namespace std;

// Type Aliases
typedef long long int ll;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

// Inline Functions
inline bool chmax(int &a, const int &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

inline bool chmin(int &a, const int &b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

// Removed unused code for brevity...

int main() {
  ios::sync_with_stdio(false);
  int n, m, k;
  while (scanf("%d%d%d", &n, &m, &k), n) {
    // Removed unused code for brevity...
    vector<P> shoolack(n);
    for (int i = 0; i < n; i++)
      scanf("%lf%lf", &shoolack[i].X, &shoolack[i].Y);
    R best = 2000;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!check(temp, best - EPS, shoolack, i, j))
          continue;
        R l = EPS, r = best;
        for (int itr = 0; itr < 50; itr++) {
          R m = (l + r) * (R).5;
          if (check(temp, m, shoolack, i, j))
            r = m;
          else
            l = m;
        }
        best = r;
      }
    }
    printf("%.10f\n", (double)best);
  }
  return 0;
}