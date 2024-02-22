#include <iostream>
#include <cmath>
#include <iomanip>

const double EPS = 1e-4;

double calc(double ra, double rb, double s) {
  double lb = std::abs(ra - rb);
  double ub = ra + rb;
  for (int i = 0; i < 80; ++i) {
    double d = (lb + ub) / 2;
    double tha = std::acos((ra * ra + d * d - rb * rb) / (2.0 * d * ra));
    double thb = std::acos((rb * rb + d * d - ra * ra) / (2.0 * d * rb));
    double sum = ra * ra * tha + rb * rb * thb - ra * d * std::sin(tha);
    if (sum > s) {
      lb = d;
    } else {
      ub = d;
    }
  }
  return ub;
}

bool judge(double x, double y, double r, double W, double H) {
  return x - r > -EPS && x + r < W + EPS && y - r > -EPS && y + r < H + EPS;
}

bool solve(double W, double H, double sa, double sb, double sc, bool reversed) {
  double ra = std::sqrt(sa / M_PI);
  double rb = std::sqrt(sb / M_PI);
  if (2.0 * ra > W + EPS || 2.0 * ra > H + EPS)
    return false;
  if (2.0 * rb > W + EPS || 2.0 * rb > H + EPS)
    return false;
  double D = calc(ra, rb, sc);
  double xa = ra;
  double ya = ra;
  const double minWH = std::min(W, H);
  const double sqD = D * D;
  for (double xb : {ra, rb, W - rb}) {
    double dy = std::sqrt(sqD - (xa - xb) * (xa - xb));
    for (int sign = -1; sign <= 1; sign += 2) {
      double yb = ya + sign * dy;
      if (judge(xb, yb, rb, W, H)) {
        if (not reversed) {
          std::cout << std::fixed << std::setprecision(9) << xa << " " << ya << " " << ra << " " << xb << " " << yb << " " << rb << "\n";
        } else {
          std::cout << std::fixed << std::setprecision(9) << xb << " " << yb << " " << rb << " " << xa << " " << ya << " " << ra << "\n";
        }
        return true;
      }
    }
  }
  for (double yb : {ra, rb, H - rb}) {
    double dx = std::sqrt(sqD - (ya - yb) * (ya - yb));
    for (int sign = -1; sign <= 1; sign += 2) {
      double xb = xa + sign * dx;
      if (judge(xb, yb, rb, W, H)) {
        if (not reversed) {
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
    std::cout << "impossible\n";
  }
  return 0;
}