#include <iostream>
#include <cmath>

const double EPS = 1e-4;

double calc(double ra, double rb, double s) {
  double lb = std::abs(ra - rb);
  double ub = ra + rb;
  for (int _ = 0; _ < 80; ++_) {
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
  int scaled_x = x * 1e4;
  int scaled_y = y * 1e4;
  int scaled_r = r * 1e4;
  int scaled_W = W * 1e4;
  int scaled_H = H * 1e4;
  return scaled_x - scaled_r > -EPS && scaled_x + scaled_r < scaled_W + EPS && scaled_y - scaled_r > -EPS && scaled_y + scaled_r < scaled_H + EPS;
}

bool solve(double W, double H, double sa, double sb, double sc, bool reversed) {
  double ra = sa / M_PI;
  double rb = sb / M_PI;
  double min_WH = std::min(W, H);
  if (2.0 * ra > min_WH + EPS)
    return false;
  if (2.0 * rb > min_WH + EPS)
    return false;
  double D = calc(ra, rb, sc);
  double xa = ra;
  double ya = ra;
  for (double xb : {ra, rb, W - rb}) {
    double dy = std::sqrt(D * D - (xa - xb) * (xa - xb));
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
    double dx = std::sqrt(D * D - (ya - yb) * (ya - yb));
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
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
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