#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MN = 501 * 1000 * 1000;
ll m, t, w, d, u, h, tu, th, x;

ll gcd(ll a, ll b) {
  while (b) {
    ll tmp = a;
    a = b;
    b = tmp % b;
  }
  return a;
}

void ext_gcd(ll a, ll b, ll &x, ll &y) {
  x = 1, y = 0;
  ll x1 = 0, y1 = 1, a1 = a, b1 = b;
  while (b1) {
    ll q = a1 / b1;
    tie(x, x1) = make_tuple(x1, x - q * x1);
    tie(y, y1) = make_tuple(y1, y - q * y1);
    tie(a1, b1) = make_tuple(b1, a1 - q * b1);
  }
}

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
  int th = t / h;
  int upper_bound = (t - w) / u;
  for (int i = 0; i < t; i += h) {
    if (s < n) {
      res += max(0, i / u - l);
      l = i / u;
    }
    s += x;
    if (s >= th)
      s -= th;
  }
  res += max(0, upper_bound - l);
  return res;
}

int main() {
  scanf("%lld %lld %d %lld %lld", &w, &d, &n, &m, &t);
  w++;
  d--;
  printf("%.20f\n", 1.0 * solve() / tu);
  return 0;
}