#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pullull;
typedef pair<ll, int> plli;
typedef pair<double, int> pdbi;
typedef pair<int, pii> pipii;
typedef pair<ll, pll> plpll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<pii> vpii;
typedef vector<vector<int>> mat;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, n) for (int i = (n); i > 0; i--)
#define rrep2(i, a, b) for (int i = (a); i > b; i--)
#define pb push_back
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
const ll hmod1 = 999999937;
const ll hmod2 = 1000000000 + 9;
const int INF = 1 << 30;
const ll mod = 1000000000 + 7;
const int dx4[4] = {1, 0, -1, 0};
const int dy4[4] = {0, 1, 0, -1};
const int dx8[8] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy8[8] = {0, 1, -1, 1, -1, 0, 1, -1};
const double pi = 3.141592653589793;
#define addm(X, Y) (X) = ((X) + ((Y) % mod) + mod) % mod
#define inside(y, x, h, w)                                                     \
  (0 <= (y) && (y) < (h) && 0 <= (x) && (x) < (w)) ? true : false

const int MAX_N = 300000;
vector<int> lists;
bool checked[MAX_N + 1] = {};

void sieve() {
  rep2(i, 2, MAX_N + 1) {
    if (checked[i]) continue;
    if (i % 7 == 1 || i % 7 == 6) {
      lists.push_back(i);
      int k = 1;
      while (i * k <= MAX_N) {
        checked[i * k] = true;
        k++;
      }
    }
  }
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  sieve();
  while (true) {
    int n;
    cin >> n;
    if (n == 1) break;
    vector<int> ans;
    for (auto p : lists) {
      if (p * p > n) break;
      if (n % p == 0) ans.push_back(p);
    }
    if (n > MAX_N) ans.pb(n);
    cout << n << ':';
    rep(i, ans.size()) { cout << " " << ans[i]; }
    cout << endl;
  }
}
