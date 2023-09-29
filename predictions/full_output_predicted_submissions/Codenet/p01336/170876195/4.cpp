#include <algorithm>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
#ifdef _MSC_VER
#define __typeof__ decltype
template <class T> int __builtin_popcount(T n) {
  return n ? 1 + __builtin_popcount(n & (n - 1)) : 0;
}
#endif
#define foreach(it, c)                                                         \
  for (__typeof__((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define CLEAR(arr, val) memset(arr, val, sizeof(arr))
#define rep(i, n) for (int i = 0; i < n; ++i)
template <class T> void max_swap(T &a, const T &b) { a = max(a, b); }
template <class T> void min_swap(T &a, const T &b) { a = min(a, b); }
typedef long long ll;
typedef pair<int, int> pint;
const double PI = acos(-1.0);
const int dx[] = {0, 1, 1, -1};
const int dy[] = {