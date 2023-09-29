#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;
const double EPS = 1e-4;
double calc(double ra, double rb, double s) {
  double lb = abs(ra - rb);
  double ub = ra + rb;
  REP(_, 64) {
    double d = (lb + ub) / 2;
    double tha = acos((ra * ra + d * d - rb * rb) / (2.0 * d * ra));
    double thb = acos((rb * rb + d * d - ra * ra) / (2.0 * d * rb));
    double sum = ra * ra * tha + rb * rb * thb - ra * d * sin(tha);
    if (sum > s) {
      lb = d;
    } else {
      ub = d;
    }
  }
  return ub;
}
inline double sq(double x) { return x * x; }
inline bool judge(double x, double y, double r, double W, double H) {
  return x - r > -EPS && x + r < W + EPS && y - r > -EPS && y + r < H + EPS;
}
bool solve(double W, double H, double sa, double sb, double sc, bool reversed) {
  double ra = sqrt(sa / M_PI);
  double rb = sqrt(sb / M_PI);
  if (2.0 * ra > min(W, H) + EPS)
    return false;
  if (2.0 * rb > min(W, H) + EPS)
    return false;
  double D = calc(ra, rb, sc);
  double xa = ra;
  double ya = ra;
  for (double xb : {ra, rb, W - rb}) {
    double dy = sqrt(sq(D) - sq(xa - xb));
    for (int sign = -1; sign <= 1; sign += 2) {
      double yb = ya + sign * dy;
      if (judge(xb, yb, rb, W, H)) {
        if (not reversed) {
          printf("%.9f %.9f %.9f %.9f %.9f %.9f\n", xa, ya, ra, xb, yb, rb);
        } else {
          printf("%.9f %.9f %.9f %.9f %.9f %.9f\n", xb, yb, rb, xa, ya, ra);
        }
        return true;
      }
    }
  }
  for (double yb : {ra, rb, H - rb}) {
    double dx = sqrt(sq(D) - sq(ya - yb));
    for (int sign = -1; sign <= 1; sign += 2) {
      double xb = xa + sign * dx;
      if (judge(xb, yb, rb, W, H)) {
        if (not reversed) {
          printf("%.9f %.9f %.9f %.9f %.9f %.9f\n", xa, ya, ra, xb, yb, rb);
        } else {
          printf("%.9f %.9f %.9f %.9f %.9f %.9f\n", xb, yb, rb, xa, ya, ra);
        }
        return true;
      }
    }
  }
  return false;
}
int main() {
  double W, H, sa, sb, sc;
  while (cin >> W >> H >> sa >> sb >> sc && W > 0) {
    if (solve(W, H, sa, sb, sc, false))
      continue;
    if (solve(W, H, sb, sa, sc, true))
      continue;
    cout << "impossible" << endl;
  }
  return 0;
}
