#include <cstdio>

typedef long long ll;

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

int solve(int w, int d, int n, int m, int t) {
  m = t - m % t;
  int u = gcd(t, w + d);
  int h = gcd(t, m);
  int tu = t / u;
  int th = t / h;
  ll xx, y;
  ext_gcd(m, t, xx, y);
  int x = ((xx % th) + th) % th;
  
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
  int w, d, n, m, t;
  scanf("%d %d %d %d %d", &w, &d, &n, &m, &t);
  
  w++;
  d--;
  
  int result = solve(w, d, n, m, t);
  int u = gcd(t, w + d);
  int tu = t / u;
  
  printf("%.20f\n", 1.0 * result * (1.0 / tu));
  return 0;
}