#include <algorithm>
#include <assert.h>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long int ll;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
#define REP(i, x) for (int i = 0; i < (x); i++)
#define REPS(i, x) for (int i = 1; i <= (x); i++)
#define RREP(i, x) for (int i = ((x)-1); i >= 0; i--)
#define RREPS(i, x) for (int i = ((x)); i > 0; i--)
#define FOR(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define RFOR(i, c) for (__typeof((c).rbegin()) i = (c).rbegin(); i != (c).rend(); i++)
#define ALL(container) (container).begin(), (container).end()
#define RALL(container) (container).rbegin(), (container).rend()
#define SZ(container) container.size()
#define mp(a, b) make_pair(a, b)
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());

// Rest of the program...

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