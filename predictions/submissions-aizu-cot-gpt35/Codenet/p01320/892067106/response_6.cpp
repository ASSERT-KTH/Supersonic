#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

typedef double R;
typedef complex<R> P;

const R INF = 1e8;
const R EPS = 1e-6;

struct S {
  P p1, p2;
};

struct MSQ {
  int m, k;
  vector<P> p;
  vector<S> s;

  MSQ(int m, int k) : m(m), k(k) {
    for (int i = 0; i < m; i++) {
      R angle = 2 * M_PI * i / m + M_PI * 0.5;
      p.push_back(polar((R)1, angle));
    }