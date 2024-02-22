#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

typedef complex<double> P;

struct S {
  P p1, p2;
  S(const P &p1, const P &p2) : p1(p1), p2(p2) {}
  S() {}
};

struct MSQ : public vector<P> {
  MSQ(int m, int k) {
    for (int i = 0; i < m; i++) {
      double angle = 2 * M_PI * i / m + M_PI / 2;
      push_back(polar(1.0, angle));
    }
    for (int i = 0; i < m; i++) {
      P p1 = at(i);
      P p2 = at((i + k) % m);
      push_back(p1);
      push_back(p2);
    }
    reverse(begin(), end());
  }
};
