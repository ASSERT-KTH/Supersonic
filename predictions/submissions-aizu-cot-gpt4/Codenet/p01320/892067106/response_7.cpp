#include <algorithm>
#include <complex>
#include <vector>
#include <cstdio>
#include <cassert>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef vector<int> vi;
#define REP(i, x) for (int i = 0; i < (int)(x); ++i)
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

// ... rest of the code ...

int main() {
  ios::sync_with_stdio(false);
  while (cin >> n >> m >> k, n) {
    MSQ temp(m, k);
    vector<P> shoolack(n);
    REP(i, n) cin >> shoolack[i];
    R best = 2000;
    REP(i, n) REP(j, m) {
      if (!check(temp, best - EPS, shoolack, i, j))
        continue;
      R l = EPS, r = best;
      REP(itr, 50) {
        R m = (l + r) * .5;
        if (check(temp, m, shoolack, i, j))
          r = m;
        else
          l = m;
      }
      best = r;
    }
    printf("%.10f\n", (double)best);
  }
  return 0;
}