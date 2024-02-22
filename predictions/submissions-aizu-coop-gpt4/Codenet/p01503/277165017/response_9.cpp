#include <cassert>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const int MN = 501 * 1000 * 1000;

ll gcd(ll a, ll b) {
  if (!a)
    return b;
  return gcd(b % a, a);
}

ll ext_gcd(ll a, ll b, ll &x, ll &y) {
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

void init(int &m, int t, int &u, int &h, int &tu, int &th, int w, int d, ll &x) {
  m = t - m % t;
  u = gcd(t, w + d), h = gcd(t, m);
  tu = t / u;
  th = t / h;
  ll xx, y;
  ext_gcd(m, t, xx, y);
  x = ((xx % th) + th) % th;
}

int solve(int w, int d, int n, int m, int t) {
  int u, h, tu, th, x;
  init(m, t, u, h, tu, th, w, d, x);
  
  int res = 0;
  int l = 0;
  int s = 0;
  int th = t / h;
  
  for (int i = 0; i < t; i += h) {
    if (s < n) {
      res += max(0, (i - w) * tu - l);
      l = i * tu;
    }
    ++s;
    if (s >= th)
      s -= th;
  }
  res += max(0, t * tu - w * tu - l);
  return res;
}

int main() {
  int w, d, n, m, t;
  cin >> w >> d >> n >> m >> t;
  ++w;
  --d;
  double tu_inv = 1.0 / (t / gcd(t, w + d));
  printf("%.20f\n", tu_inv * solve(w, d, n, m, t));
  return 0;
}