#include <iostream>
#include <cmath>

const double EPS = 1e-9;

double calc(double ra, double rb, double s) {
  double lb = std::abs(ra - rb);
  double ub = ra + rb;
  int iterations = 40;  // Reduce the number of iterations
  while (iterations--) {
    double d1 = lb + (ub - lb) / 3;
    double d2 = ub - (ub - lb) / 3;
    double tha1 = std::acos((ra * ra + d1 * d1 - rb * rb) / (2.0 * d1 * ra));
    double thb1 = std::acos((rb * rb + d1 * d1 - ra * ra) / (2.0 * d1 * rb));
    double sum1 = ra * ra * tha1 + rb * rb * thb1 - ra * d1 * std::sin(tha1);
    double tha2 = std::acos((ra * ra + d2 * d2 - rb * rb) / (2.0 * d2 * ra));
    double thb2 = std::acos((rb * rb + d2 * d2 - ra * ra) / (2.0 * d2 * rb));
    double sum2 = ra * ra * tha2 + rb * rb * thb2 - ra * d2 * std::sin(tha2);
    if (sum1 > sum2) {
      ub = d2;
    } else {
      lb = d1;
    }
  }
  return ub;
}

double sq(double x) {
  return x * x;
}

bool judge(double x, double y, double r, double W, double H) {
  return x - r > -EPS && x + r < W + EPS && y - r > -EPS && y + r < H + EPS;
}

bool solve(double W, double H, double sa, double sb, double sc, bool reversed) {
  double ra = std::sqrt(sa / M_PI);
  double rb = std::sqrt(sb / M_PI);
  if (2.0 * ra > std::min(W, H) + EPS)
    return false;
  if (2.0 * rb > std::min(W, H) + EPS)
    return false;
  double D = calc(ra, rb, sc);
  double xa = ra;
  double ya = ra;
  for (double xb : {ra, rb, W - rb}) {
    double dy = std::sqrt(sq(D) - sq(xa - xb));
    for (int sign = -1; sign <= 1; sign += 2) {
      double yb = ya + sign * dy;
      if (judge(xb, yb, rb, W, H)) {
        if (!reversed) {
          std::cout << std::fixed << std::setprecision(9) << xa << " " << ya << " " << ra << " " << xb << " " << yb << " " << rb << "\n";
        } else {
          std::cout << std::fixed << std::setprecision(9) << xb << " " << yb << " " << rb << " " << xa << " " << ya << " " << ra << "\n";
        }
        return true;
      }
    }
  }
  for (double yb : {ra, rb, H - rb}) {
    double dx = std::sqrt(sq(D) - sq(ya - yb));
    for (int sign = -1; sign <= 1; sign += 2) {
      double xb = xa + sign * dx;
      if (judge(xb, yb, rb, W, H)) {
        if (!reversed) {
          std::cout << std::fixed << std::setprecision(9) << xa << " " << ya << " " << ra << " " << xb << " " << yb << " " << rb << "\n";
        } else {
          std::cout << std::fixed << std::setprecision(9) << xb << " " << yb << " " << rb << " " << xa << " " << ya << " " << ra << "\n";
        }
        return true;
      }
    }
  }
  return false;
}

int main() {
  double W, H, sa, sb, sc;
  while (std::cin >> W >> H >> sa >> sb >> sc && W > 0) {
    if (solve(W, H, sa, sb, sc, false))
      continue;
    if (solve(W, H, sb, sa, sc, true))
      continue;
    std::cout << "impossible" << std::endl;
  }
  return 0;
}