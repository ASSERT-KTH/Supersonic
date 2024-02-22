#include <iostream>
#include <cmath>
#include <assert.h>

const double EPS = 1e-4;

double calc(double ra, double rb, double s) {
    double lb = abs(ra - rb);
    double ub = ra + rb;
    for(int _ = 0; _ < 80; _++) {
        double d = (lb + ub) / 2;
        double ra_sq = ra * ra;
        double rb_sq = rb * rb;
        double d_sq = d * d;
        double tha = acos((ra_sq + d_sq - rb_sq) / (2.0 * d * ra));
        double sin_tha = sin(tha);
        double thb = acos((rb_sq + d_sq - ra_sq) / (2.0 * d * rb));
        double sum = ra_sq * tha + rb_sq * thb - ra * d * sin_tha;
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
    if (2.0 * ra > std::min(W, H) + EPS)
        return false;
    if (2.0 * rb > std::min(W, H) + EPS)
        return false;
    double D = calc(ra, rb, sc);
    double xa = ra;
    double ya = ra;
    double D_sq = sq(D);
    double ra_sq = sq(ra);
    double rb_sq = sq(rb);
    for (double xb : {ra, rb, W - rb}) {
        double dy_sq = D_sq - sq(xa - xb);
        if(dy_sq < 0) continue;
        double dy = sqrt(dy_sq);
        for (int sign = -1; sign <= 1; sign += 2) {
            double yb = ya + sign * dy;
            if (judge(xb, yb, rb, W, H)) {
                assert(judge(xa, ya, ra, W, H));
                assert(abs(hypot(xa - xb, ya - yb) - D) < EPS);
                if (!reversed) {
                    std::cout << xa << ' ' << ya << ' ' << ra << ' ' << xb << ' ' << yb << ' ' << rb << '\n';
                } else {
                    std::cout << xb << ' ' << yb << ' ' << rb << ' ' << xa << ' ' << ya << ' ' << ra << '\n';
                }
                return true;
            }
        }
    }
    for (double yb : {ra, rb, H - rb}) {
        double dx_sq = D_sq - sq(ya - yb);
        if(dx_sq < 0) continue;
        double dx = sqrt(dx_sq);
        for (int sign = -1; sign <= 1; sign += 2) {
            double xb = xa + sign * dx;
            if (judge(xb, yb, rb, W, H)) {
                assert(judge(xa, ya, ra, W, H));
                assert(abs(hypot(xa - xb, ya - yb) - D) < EPS);
                if (!reversed) {
                    std::cout << xa << ' ' << ya << ' ' << ra << ' ' << xb << ' ' << yb << ' ' << rb << '\n';
                } else {
                    std::cout << xb << ' ' << yb << ' ' << rb << ' ' << xa << ' ' << ya << ' ' << ra << '\n';
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