#include <iostream>
#include <vector>
#include <array>
#include <complex>
#include <algorithm>
#include <cmath>
#include <utility>

using std::vector;
using std::complex;
using std::pair;
using std::cin;
using std::cout;
using std::sort;
using std::endl;
using std::array;
using ll = long long;
using ld = long double;
using P = complex<ld>;
using G = vector<P>;
using C = pair<ld, P>;

const ld pi = acos(-1);
const ld eps = 1e-10;

ld cross(const P &a, const P &b) {
  return a.real() * b.imag() - a.imag() * b.real();
}

ld dot(const P &a, const P &b) {
  return a.real() * b.real() + a.imag() * b.imag();
}

// ... continue with the rest of the code