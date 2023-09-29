#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> PI;
#define EPS (1e-4)
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define REP(i, n) rep(i, n)
#define F first
#define S second
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define min3(a, b, c) min((a), min((b), (c)))
#define min4(a, b, c, d) min((a), min3((b), (c), (d)))
#define SZ(a) (int)((a).size())
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) a.rbegin(), a.rend()
#define FLL(a, b) memset((a), b, sizeof(a))
#define CLR(a) memset((a), 0, sizeof(a))
#define declare(a, it) __typeof(a) it = (a)
#define FOR(it, a) for (declare(a.begin(), it); it != a.end(); ++it)
#define FORR(it, a) for (declare(a.rbegin(), it); it != a.rend(); ++it)
template <typename T, typename U>
ostream &operator<<(ostream &out, const pair<T, U> &val) {
  return out << "(" << val.F << ", " << val.S << ")";
}
template <class T> ostream &operator<<(ostream &out, const vector<T> &val) {