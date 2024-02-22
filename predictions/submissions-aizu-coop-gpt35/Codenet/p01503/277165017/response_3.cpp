#include <cstdio>

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
  m = t - m % t;
  int u = gcd(t, w + d);
  int h = gcd(t, m);
  int tu = t / u;
  int x;
  {
    ll xx, y;
    ext_gcd(m, t, xx, y);
    x = ((xx % (t / h)) + (t / h)) % (t / h);
  }
  int res = 0;
  int l = 0;
  int s = 0;
  int th = t / h;
  for (int i = 0; i < t; i += h) {
    if (s < n) {
      res += (i - w) / u - l;
      l = i / u;
    }
    s += x;
    if (s >= th)
      s -= th;
  }
  res += (t - w) / u - l;
  return res;
}

int main() {
  int w, d, n, m, t;
  scanf("%d%d%d%d%d", &w, &d, &n, &m, &t);
  w++;
  d--;
  printf("%.20f\n", 1.0 * solve(w, d, n, m, t) / (t / gcd(t, w + d)));
  return 0;
}