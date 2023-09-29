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
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
template <typename T> T &max(T &a, T &b) {
  if (a >= b)
    return a;
  return b;
}
template <typename T> T &min(T &a, T &b) {
  if (a < b)
  