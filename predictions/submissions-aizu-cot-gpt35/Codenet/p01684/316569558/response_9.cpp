#include <iostream>
#include <cmath>
using namespace std;

const double EPS = 1e-4;

double calc(double ra, double rb, double s) {
  double lb = abs(ra - rb);
  double ub = ra + rb;
  
  double ra2 = ra * ra;
  double rb2 = rb * rb;
  double ra_d = ra * d;
  
  for (int _ = 0; _ < 80; ++_) {
    double d = (lb + ub) / 2;
    double tha = acos((ra2 + d * d - rb2) / (2.0 * d * ra));
    double thb = acos((rb2 + d * d - ra2) / (2.0 * d * rb));
    double sum = ra2 * tha + rb2 * thb - ra_d * sin(tha);
    if (sum > s) {
      lb = d;
    } else {
      ub = d;
    }
  }
  
  return ub;
}

double sq(double x) { return x * x; }

bool judge(double x, double y, double r, double W, double H) {
  return x - r > -EPS && x + r < W + EPS && y - r > -EPS && y + r < H + EPS;
}

bool solve(double W, double H, double sa, double sb, double sc, bool reversed) {
  double ra = sqrt(sa / M_PI);
  double rb = sqrt(sb / M_PI);
  double min_WH = min(W, H) + EPS;
  
  if (2.0 * ra > min_WH)
    return false;
  if (2.0 * rb > min_WH)
    return false;
  
  double D = calc(ra, rb, sc);
  double xa = ra;
  double ya = ra;
  
  for (double xb = ra; xb <= W - rb; xb += (W - rb - ra) * 2) {
    double dy = sqrt(sq(D) - sq(xa - xb));
    for (int sign = -1; sign <= 1; sign += 2) {
      double yb = ya + sign * dy;
      if (judge(xb, yb, rb, W, H)) {
        if (!reversed) {
          printf("%.9f %.9f %.9f %.9f %.9f %.9f\n", xa, ya, ra, xb, yb, rb);
        } else {
          printf("%.9f %.9f %.9f %.9f %.9f %.9f\n", xb, yb, rb, xa, ya, ra);
        }
        return true;
      }
    }
  }
  
  for (double yb = ra; yb <= H - rb; yb += (H - rb - ra) * 2) {
    double dx = sqrt(sq(D) - sq(ya - yb));
    for (int sign = -1; sign <= 1; sign += 2) {
      double xb = xa + sign * dx;
      if (judge(xb, yb, rb, W, H)) {
        if (!reversed) {
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