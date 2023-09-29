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
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  ll d = ext_gcd(b, a % b, y, x);
  y -= a / b * x;
  return d;
}
int solve(int w, int d, int n, int m, int t) {
  m = t - m % t;
  ll u = gcd(t, w + d), h = gcd(t, m);
  ll tu = t / u;
  ll th = t / h;
  ll xx, y;
  ext_gcd(m, t, xx, y);
  ll x = ((xx % th) + th) % th;
  int res = 0;
  int l = 0;
  int s = 0;
  th = t / h;
  for (int i = 0; i < t; i += h) {
    if (s < n) {
      res += std::max(0, (i - w) / (int)u - l);
      l = i / (int)u;
    }
    s += x;
    if (s >= th)
      s -= th;
  }
  res += std::max(0, (t - w) / (int)u - l);
  return res;
}
int main() {
  int w, d, n, m, t;
  scanf("%d%d%d%d%d", &w, &d, &n, &m, &t);
  w++;
  d--;
  printf("%.20f\n", 1.0 * solve(w, d, n, m, t) / (t/gcd(t, w+d)));
  return 0;
}