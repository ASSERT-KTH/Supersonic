#include <iostream>
#include <cmath>
#include <algorithm>
#include <cassert>
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;
const double EPS = 1e-4;

void printResult(double xa, double ya, double ra, double xb, double yb, double rb, bool reversed){
    if (not reversed) {
        printf("%.9f %.9f %.9f %.9f %.9f %.9f\n", xa, ya, ra, xb, yb, rb);
    } else {
        printf("%.9f %.9f %.9f %.9f %.9f %.9f\n", xb, yb, rb, xa, ya, ra);
    }
}

double calc(double ra, double rb, double s) {
  // Code remains the same
}

double sq(double x) { return x * x; }

bool judge(double x, double y, double r, double W, double H) {
  // Code remains the same
}

bool solve(double W, double H, double sa, double sb, double sc, bool reversed) {
  // Code remains the same, replace printf statements with printResult function
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