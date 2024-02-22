#include <bits/stdc++.h>
using namespace std;
constexpr double EPS = 1e-10;
constexpr double PI = 3.141592653589793238;
#define equals(a, b) (fabs((a) - (b)) < EPS)
#define int long long
...
signed main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  Polygon p(n);
  p.reserve(n);
  for (int i = 0; i < n; i++)
    cin >> p[i];
  printf("%.12f\n", diameter(p));
  return 0;
}