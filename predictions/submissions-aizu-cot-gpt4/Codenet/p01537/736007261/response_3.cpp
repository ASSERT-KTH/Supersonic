#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
#define all(c) (c).begin(), (c).end()
#define loop(i, a, b) for (ll i = a; i < ll(b); ++i)
#define rep(i, b) loop(i, 0, b)
#define each(e, c) for (auto &e : c)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#ifdef DEBUG
#define dump(...)                                                              \
  (cerr << #__VA_ARGS__ << " = " << (DUMP(), __VA_ARGS__).str() << " ["        \
        << __LINE__ << "]" << endl)
struct DUMP : ostringstream {
  template <class T> DUMP &operator,(const T &t) {
    if (this->tellp())
      *this << ", ";
    *this << t;
    return *this;
  }
};
#else
#define dump(...)
#endif
template <class T> ostream &operator<<(ostream &os, vector<T> const &v) {
  rep(i, v.size()) os << v[i] << (i + 1 == (int)v.size() ? "" : " ");
  return os;
}
#include <complex>
using namespace std;
#define curr(g, i) g[i]
#define next(g, i) g[(i + 1) % g.size()]
#define self (*this)
typedef long double R;
constexpr R eps = 1e-10;
constexpr R inf = 1e12;
constexpr R pi = acos(-1);
typedef complex<R> P;
inline R arg(P a, P b, P c) {
  R th = arg((a - b) / (c - b));
  return th > 0 ? th : th + 2 * pi;
}
inline bool comp_x(const P &a, const P &b) {
  return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
}
inline bool comp_y(const P &a, const P &b) {
  return imag(a) != imag(b) ? imag(a) < imag(b) : real(a) < real(b);
}
P CENTER = P();
bool comp_arg(const P &a, const P &b) {
  return arg(a, CENTER, CENTER + (R)1.) < arg(b, CENTER, CENTER + (R)1.);
}
namespace std {
bool operator<(P const &a, P const &b) { return comp_x(a, b); }
} // namespace std
inline R cross(const P &a, const P &b) { return imag(conj(a) * b); }
inline R dot(const P &a, const P &b) { return real(conj(a) * b); }
// Remainder of the program...