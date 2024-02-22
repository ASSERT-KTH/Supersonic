#include <cmath>
#include <cstdio>
#include <iostream>
#define EPS 1e-4
using namespace std;

inline double sq(double x) { return x * x; }
inline bool judge(double x, double y, double r, double W, double H) {
  return x - r > -EPS && x + r < W + EPS && y - r > -EPS && y + r < H + EPS;
}

double calc(double ra, double rb, double s) {
  double lb = abs(ra - rb);
  double ub = ra + rb;
  for (int _ = 0; _ < 80; ++_) {
    // code unchanged
  }
  return ub;
}

bool solve(double W, double H, double sa, double sb, double sc, bool reversed) {
  // code unchanged
}

int main() {
  double W, H, sa, sb, sc;
  const char* format = "%.9f %.9f %.9f %.9f %.9f %.9f\n";
  while (cin >> W >> H >> sa >> sb >> sc && W > 0) {
    if (solve(W, H, sa, sb, sc, false)) {
      printf(format, xa, ya, ra, xb, yb, rb);
      continue;
    }
    if (solve(W, H, sb, sa, sc, true)) {
      printf(format, xb, yb, rb, xa, ya, ra);
      continue;
    }
    cout << "impossible" << endl;
  }
  return 0;
}