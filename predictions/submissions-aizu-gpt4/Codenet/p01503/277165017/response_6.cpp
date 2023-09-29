#include <cstdio>
#include <algorithm>
typedef long long ll;

const int MN = 501 * 1000 * 1000;
ll gcd(ll a, ll b) {
  while(b) {
    a %= b;
    std::swap(a, b);
  }
  return a;
}
ll ext_gcd(ll a, ll b, ll &x, ll &y) {
  if(!b) {
    x = 1;
    y = 0;
    return a;
  }
  ll d = ext_gcd(b, a%b, y, x);
  y -= a / b * x;
  return d;
}

ll w, d, n, m, t, u, h, tu, th, x;
void init() {
  m = t - m % t;
  u = gcd(t, w + d), h = gcd(t, m);
  tu = t / u;
  th = t / h;
  ll xx, y;
  ext_gcd(m, t, xx, y);
  x = ((xx % th) + th) % th;
}
ll solve() {
  init();
  ll res = 0;
  ll l = 0;
  ll s = 0;
  th = t / h;
  for (ll i = 0; i < t; i += h) {
    if (s < n) {
      res += std::max((ll)0, (i - w) / u - l);
      l = i / u;
    }
    s += x;
    if (s >= th)
      s -= th;
  }
  res += std::max((ll)0, (t - w) / u - l);
  return res;
}
int main() {
  scanf("%lld %lld %lld %lld %lld", &w, &d, &n, &m, &t);
  w++;
  d--;
  printf("%.20f\n", 1.0 * solve() / tu);
  return 0;
}