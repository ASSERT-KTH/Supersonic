#include <iostream>
#include <cmath>
#include <cassert>
#include <iomanip>

using namespace std;

const double EPS = 1e-4;

double calc(double ra, double rb, double s) {
    double lb = abs(ra - rb);
    double ub = ra + rb;
    for(int _ = 0; _ < 80; _++) {
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

bool judge(double x, double y, double r, double W, double H) {
    return min(min(x, W - x), min(y, H - y)) >= r - EPS;
}

bool print_res(double xa, double ya, double ra, double xb, double yb, double rb, bool reversed) {
    if (reversed) {
        swap(xa, xb);
        swap(ya, yb);
        swap(ra, rb);
    }
    cout << fixed << setprecision(9) << xa << " " << ya << " " << ra << " " << xb << " " << yb << " " << rb << "\n";
    return true;
}

bool solve(double W, double H, double sa, double sb, double sc, bool reversed) {
    double ra = sqrt(sa / M_PI);
    double rb = sqrt(sb / M_PI);
    double minDimension = min(W, H);
    if (2.0 * ra > minDimension + EPS || 2.0 * rb > minDimension + EPS)
        return false;
    double D = calc(ra, rb, sc);
    double xa = ra;
    double ya = ra;
    double candidates[] = {ra, rb, W - rb};
    for (double xb : candidates) {
        double dy = sqrt(D * D - (xa - xb) * (xa - xb));
        for (int sign = -1; sign <= 1; sign += 2) {
            double yb = ya + sign * dy;
            if (judge(xb, yb, rb, W, H)) {
                assert(judge(xa, ya, ra, W, H));
                assert(abs(hypot(xa - xb, ya - yb) - D) < EPS);
                return print_res(xa, ya, ra, xb, yb, rb, reversed);
            }
        }
    }
    return false;
}

int main() {
    double W, H, sa, sb, sc;
    while (cin >> W >> H >> sa >> sb >> sc && W > 0) {
        if (solve(W, H, sa, sb, sc, false) || solve(W, H, sb, sa, sc, true))
            continue;
        cout << "impossible" << endl;
    }
    return 0;
}