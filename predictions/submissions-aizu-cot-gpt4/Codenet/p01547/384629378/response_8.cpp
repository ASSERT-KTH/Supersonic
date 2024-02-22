#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
#include <cmath>

#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef double D;
typedef std::complex<D> P;
typedef std::pair<P, P> L;
typedef std::vector<P> VP;
typedef std::vector<VP> Vcon;
constexpr D EPS = 1e-7;
#define X real()
#define Y imag()
#define LE(n, m) ((n) < (m) + EPS)
#define GE(n, m) ((n) + EPS > (m))
#define EQ(n, m) (std::abs((n) - (m)) < EPS)

// Rest of the code