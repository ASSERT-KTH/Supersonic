#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const double EPS = 1e-6;

struct MSQ : public vector<complex<double>> {
  vector<complex<double>> p;
  vector<complex<double>> s;
  int m, k;
  MSQ(int m, int k) : m(m), k(k) {
    for (int i = 0; i < m; i++)
      p.push_back(polar(1.0, 2 * M_PI * i / m + M_PI * 0.5));