#include <algorithm>
#include <assert.h>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <valarray>
#include <vector>
using namespace std;
typedef long long int ll;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
#define REP(i, x) for (int i = 0; i < (int)(x); i++)
#define REPS(i, x) for (int i = 1; i <= (int)(x); i++)
#define RREP(i, x) for (int i = ((int)(x)-1); i >= 0; i--)
#define RREPS(i, x) for (int i = ((int)(x)); i > 0; i--)
#define FOR(i, c)                                                              \
  for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define RFOR(i, c)                                                             \
  for (__typeof((c).rbegin()) i = (c).rbegin(); i != (c).rend(); ++i)
#define ALL(container) (container).begin(), (container).end()
#define RALL(container) (container).rbegin(), (container).rend()
#define SZ(container) ((int)container.size())
#define mp(a, b) make_pair(a, b)
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());
template <class T> bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> ostream &operator<<(ostream &os, const vector<T> &t) {
  os << "[";
  FOR(it, t) {
    if (it != t.begin())
      os << ",";
    os << *it;
  }
  os << "]";
  return os;
}
template <class T> ostream &operator<<(ostream &os, const set<T> &t) {
  os << "{";
  FOR(it, t) {
    if (it != t.begin())
      os << ",";
    os << *it;
  }
  os << "}";
  return os;
}
template <class S, class T>
ostream &operator<<(ostream &os, const pair<S, T> &t) {
  return os << "(" << t.first << "," << t.second << ")";
}
template <class S, class T>
pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) {
  return pair<S, T>(s.first + t.first, s.second + t.second);
}
template <class S, class T>
pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) {
  return pair<S, T>(s.first - t.first, s.second - t.second);
}
namespace geom {
#define X real()
#define Y imag()
#define at(i) ((*this)[i])
#define SELF (*this)
enum { TRUE = 1, FALSE = 0, BORDER = -1 };
typedef int BOOL;
typedef double R;
const R INF = 1e8;
R EPS = 1e-6;
const R PI = 3.1415926535897932384626;
inline int sig(const R &x) { return (abs(x) < EPS ? 0 : x > 0 ? 1 : -1); }
//remaining code is same
