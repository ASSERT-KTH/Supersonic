#include <iostream>
#include <cmath>
#include <cassert>

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
    return x - r > -EPS && x + r < W + EPS && y - r > -EPS && y + r < H + EPS;
}

bool solve(double W, double H, double sa, double sb, double sc, bool reversed) {
    if (2.0 * std::sqrt(sa / M_PI) > std::min(W, H) + EPS)
        return false;
    if (2.0 * std::sqrt(sb / M_PI) > std::min(W, H) + EPS)
        return false;
    double D = calc(std::sqrt(sa / M_PI), std::sqrt(sb / M_PI), sc);
    double xa = std::sqrt(sa / M_PI);
    double ya = std::sqrt(sa / M_PI);
    for (double xb : {xa, std::sqrt(sb / M_PI), W - std::sqrt(sb / M_PI)}) {
        double dy = std::sqrt(D * D - (xa - xb) * (xa - xb));
        for (int sign = -1; sign <= 1; sign += 2) {
            double yb = ya + sign * dy;
            if (judge(xb, yb, std::sqrt(sb / M_PI), W, H)) {
                assert(judge(xa, ya, std::sqrt(sa / M_PI), W, H));
                assert((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb) - D * D < EPS * EPS);
                if (not reversed) {
                    std::cout << std::fixed << std::setprecision(9) << xa << " " << ya << " " << std::sqrt(sa / M_PI) << " " << xb << " " << yb << " " << std::sqrt(sb / M_PI) << "\n";
                } else {
                    std::cout << std::fixed << std::setprecision(9) << xb << " " << yb << " " << std::sqrt(sb / M_PI) << " " << xa << " " << ya << " " << std::sqrt(sa / M_PI) << "\n";
                }
                return true;
            }
        }
    }
    for (double yb : {ya, std::sqrt(sb / M_PI), H - std::sqrt(sb / M_PI)}) {
        double dx = std::sqrt(D * D - (ya - yb) * (ya - yb));
        for (int sign = -1; sign <= 1; sign += 2) {
            double xb = xa + sign * dx;
            if (judge(xb, yb, std::sqrt(sb / M_PI), W, H)) {
                assert(judge(xa, ya, std::sqrt(sa / M_PI), W, H));
                assert((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb) - D * D < EPS * EPS);
                if (not reversed) {
                    std::cout << std::fixed << std::setprecision(9) << xa << " " << ya << " " << std::sqrt(sa / M_PI) << " " << xb << " " << yb << " " << std::sqrt(sb / M_PI) << "\n";
                } else {
                    std::cout << std::fixed << std::setprecision(9) << xb << " " << yb << " " << std::sqrt(sb / M_PI) << " " << xa << " " << ya << " " << std::sqrt(sa / M_PI) << "\n";
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