#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double EPS = 1e-4;

double calc(double ra, double rb, double s) {
  double lb = abs(ra - rb);
  double ub = ra + rb;
  for (int _ = 0; _ < 80; ++_) {
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

double sq(double x) { return x * x; }

bool judge(double x, double y, double r, double W, double H) {
  return x - r > -EPS && x + r < W + EPS && y - r > -EPS && y + r < H + EPS;
}

void print_results(double xa, double ya, double ra, double xb, double yb, double rb, bool reversed) {
  if (!reversed) {
    cout << fixed << setprecision(9) << xa << " " << ya << " " << ra << " " << xb << " " << yb << " " << rb << "\n";
  } else {
    cout << fixed << setprecision(9) << xb << " " << yb << " " << rb << " " << xa << " " << ya << " " << ra << "\n";
  }
}

bool solve(double W, double H, double sa, double sb, double sc, bool reversed) {
  
  double ra_sq = sa / M_PI;
  double rb_sq = sb / M_PI;
  double ra = sqrt(ra_sq);
  double rb = sqrt(rb_sq);
  
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
        print_results(xa, ya, ra, xb, yb, rb, reversed);
        return true;
      }
    }
  }
  
  for (double yb : {ra, rb, H - rb}) {
    double dx = sqrt(sq(D) - sq(ya - yb));
    for (int sign = -1; sign <= 1; sign += 2) {
      double xb = xa + sign * dx;
      if (judge(xb, yb, rb, W, H)) {
        print_results(xa, ya, ra, xb, yb, rb, reversed);
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