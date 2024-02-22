#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <cstdio>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define EPS (1e-6)
#define equals(a, b) (fabs((a) - (b)) < EPS)
#define COUNTER_CLOCKWISE 1
#define CLOCKWISE -1
#define ONLINE_BACK 2
#define ONLINE_FRONT -2
#define ON_SEGMENT 0
#define MANY "Many"
#define NONE "None"

// Rest of the code remains the same except `cin`, `cout`, `endl` are replaced by `scanf`, `printf`, `'\n'` respectively.
// Also, `std::` is added before `vector`, `sort`, `unique`, `min`, `max`, `sqrt`, `fabs`, `atan2`, etc.

int main() {
  std::ios_base::sync_with_stdio(false);
  int n;
  while (scanf("%d", &n), n) {
    std::vector<Line> vec(n);
    rep(i, n) scanf("%lf %lf %lf %lf", &vec[i].p1.x, &vec[i].p1.y, &vec[i].p2.x, &vec[i].p2.y);
    compute(vec);
  }
  return 0;
}