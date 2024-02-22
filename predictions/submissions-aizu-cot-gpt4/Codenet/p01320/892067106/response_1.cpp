#include <vector>
#include <complex>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cassert>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define REP(i, x) for (int i = 0; i < (int)(x); i++)
#define REPS(i, x) for (int i = 1; i <= (int)(x); i++)
#define RREP(i, x) for (int i = ((int)(x)-1); i >= 0; i--)
#define RREPS(i, x) for (int i = ((int)(x)); i > 0; i--)
#define ALL(container) (container).begin(), (container).end()
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

// All other unchanged parts of the program...

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(0);
  while (scanf("%d %d %d", &n, &m, &k), n) {
    MSQ temp(m, k);
    vector<P> shoolack(n);
    REP(i, n) cin >> shoolack[i];
    R best = 2000;
    REP(i, n) REP(j, m) {
      if (!check(temp, best - EPS, shoolack, i, j))
        continue;
      R l = EPS, r = best;
      REP(itr, 50) {
        R m = (l + r) * (R).5;
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