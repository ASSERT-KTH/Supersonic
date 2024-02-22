#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
  while (a) {
    ll temp = a;
    a = b % a;
    b = temp;
  }
  return b;
}

ll ext_gcd(ll a, ll b, ll &x, ll &y) {
  ll xx = 0, yy = 1;
  x = 1, y = 0;
  while (a) {
    ll q = b / a;
    ll t = b % a;
    b = a;
    a = t;
    t = xx;
    xx = x - q * xx;
    x = t;
    t = yy;
    yy = y - q * yy;
    y = t;
  }
  return b;
}

int solve(int w, int d, int n, int m, int t, int tu, int th) {
  int res = 0;
  int l = 0;
  int s = 0;
  for (int i = 0; i < t; i += th) {
    if (s < n) {
      res += max(0, (i - w) / tu - l);
      l = i / tu;
    }
    s = (s + 1) % th;
  }
  res += max(0, (t - w) / tu - l);
  return res;
}

int main() {
  int w, d, n, m, t;
  cin >> w >> d >> n >> m >> t;
  w++;
  d--;
  int u = gcd(t, w + d);
  int h = gcd(t, m);
  int tu = t / u;
  int th = t / h;
  ll xx, y;
  ext_gcd(m, t, xx, y);
  int x = ((xx % th) + th) % th;
  
  printf("%.20f\n", 1.0 * solve(w, d, n, m, t, tu, th) / tu);
  
  return 0;
}