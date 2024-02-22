#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <random>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const int MN = 501 * 1000 * 1000;
inline ll gcd(ll a, ll b) {
  if (!a)
    return b;
  return gcd(b % a, a);
}
inline ll ext_gcd(ll a, ll b, ll &x, ll &y) {
  ll d = a;
  if (b) {
    d = ext_gcd(b, a % b, y, x);
    y -= a / b * x;
  } else {
    x = 1;
    y = 0;
  }
  return d;
}
int w, d, n, m, t, u, h;
int x, tu, th;
void init() {
  m = t - m % t;
  u = gcd(t, w + d), h = gcd(t, m);
  tu = t / u;
  th = t / h;
  ll xx, y;
  ext_gcd(m, t, xx, y);
  x = ((xx % th) + th) % th;
}
int solve() {
  init();
  int res = 0;
  int l = 0;
  int s = 0;
  for (int i = 0; i < t; i += h) {
    if (s < n) {
      res += max(0, (i - w) / u - l);
      l = i / u;
    }
    s += x;
    if (s >= th)
      s -= th;
  }
  res += max(0, (t - w) / u - l);
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> w >> d >> n >> m >> t;
  w++;
  d--;
  printf("%.20f\n", 1.0 * solve() / tu);
  return 0;
}