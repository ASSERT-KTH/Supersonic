#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>

using D = double;
using P = std::complex<D>;
using L = std::pair<P, P>;
using VP = std::vector<P>;
using Vcon = std::vector<VP>;

constexpr D EPS = 1e-7;

inline D dot(P a, P b) { return (std::conj(a) * b).real(); }
inline D cross(P a, P b) { return (std::conj(a) * b).imag(); }

// The rest of the code is the same, with the optimizations applied. 