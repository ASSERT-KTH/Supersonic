#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
#define y1dogwhoasjfd
#define fst first
#define scd second
#define PB push_back
#define MP make_pair
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define omajinai                                                               \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0)
#define rep(i, x) for (int i = 0; i < (int)(x); ++i)
#define rep1(i, x) for (int i = 1; i <= (int)(x); ++i)
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vpii = vector<pii>;
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> p) {
  os << "(" << p.fst << ", " << p.scd << ")";
  return os;
}
template <class T> ostream &