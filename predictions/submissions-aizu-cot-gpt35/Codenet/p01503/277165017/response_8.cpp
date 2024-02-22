#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
  while (b) {
    ll temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

ll ext_gcd(ll a, ll b, ll &x, ll &y) {
  ll xx = 0, yy = 1;
  y = 0;
  x = 1;
  while (b) {
    ll q = a / b;
    ll t = b;
    b = a % b;
    a = t;
    t = xx;
    xx = x - q * xx;
    x = t;
    t = yy;
    yy = y - q * yy;
    y = t;
  }
  return a;
}

int solve(int w, int d, int n, int m, int t) {
  int res = 0;
  int l = 0;
  int s = 0;
  int h = gcd(t, m);
  int th = t / h;
  int u = gcd(t, w + d);
  
  int x, y;
  ext_gcd(m, t, x, y);
  x = ((x % th) + th) % th;

  for (int i = 0; i < t; i += h) {
    if (s < n) {
      res += max(0, (i - w) * u - l);
      l = i * u;
    }
    s += x;
    if (s >= th)
      s -= th;
  }
  res += max(0, (t - w) * u - l);
  return res;
}

int main() {
  int w, d, n, m, t;
  cin >> w >> d >> n >> m >> t;
  w++;
  d--;
  printf("%.20f\n", 1.0 * solve(w, d, n, m, t) / t);
  return 0;
}