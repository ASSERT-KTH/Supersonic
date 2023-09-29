#include <cstdio>
typedef long long ll;

ll gcd(ll a, ll b) {
  while (b) {
    a %= b;
    std::swap(a, b);
  }
  return a;
}

ll ext_gcd(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  ll x1, y1, d;
  d = ext_gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return d;
}

int main() {
  ll w, d, n, m, t, u, h, tu, th, x;
  scanf("%lld%lld%lld%lld%lld", &w, &d, &n, &m, &t);
  w++;
  d--;
  m = t - m % t;
  u = gcd(t, w + d), h = gcd(t, m);
  tu = t / u;
  th = t / h;
  ll xx, y;
  ext_gcd(m, t, xx, y);
  x = ((xx % th) + th) % th;
  ll res = 0;
  ll l = 0;
  ll s = 0;
  for (ll i = 0; i < t; i += h) {
    if (s < n) {
      res += std::max(0LL, (i - w) / u - l);
      l = i / u;
    }
    s += x;
    if (s >= th)
      s -= th;
  }
  res += std::max(0LL, (t - w) / u - l);
  printf("%.20f\n", 1.0 * res / tu);
  return 0;
}