#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

ll gcd(ll a, ll b) {
  while (b != 0) {
    ll rem = a % b;
    a = b;
    b = rem;
  }
  return a;
}

ll ext_gcd(ll a, ll b, ll &x, ll &y) {
  x = 1, y = 0;
  ll x1 = 0, y1 = 1, a1 = a, b1 = b;
  while (b1) {
    ll q = a1 / b1;
    tie(x, x1) = make_pair(x1, x - q * x1);
    tie(y, y1) = make_pair(y1, y - q * y1);
    tie(a1, b1) = make_pair(b1, a1 - q * b1);
  }
  return a1;
}

int main() {
  ll w, d, n, m, t, u, h, tu, th, x;
  scanf("%lld %lld %lld %lld %lld", &w, &d, &n, &m, &t);
  w++;
  d--;
  m = t - m % t;
  u = gcd(t, w + d), h = gcd(t, m);
  tu = t / u;
  th = t / h;
  ll xx, y;
  ext_gcd(m, t, xx, y);
  x = ((xx % th) + th) % th;
  int res = 0;
  int l = 0;
  int s = 0;
  for (int i = 0; i < t; i += h) {
    if (s < n) {
      res += max(0LL, (i - w) / u - l);
      l = i / u;
    }
    s += x;
    if (s >= th)
      s -= th;
  }
  res += max(0LL, (t - w) / u - l);
  printf("%.20f\n", 1.0 * res / tu);
  return 0;
}