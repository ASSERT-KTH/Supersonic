#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}

ll ext_gcd(ll a, ll b, ll &x, ll &y) {
  if(!b) {
    x = 1;
    y = 0;
    return a;
  }
  ll d = ext_gcd(b, a % b, y, x);
  y -= a / b * x;
  return d;
}

const int MN = 501 * 1000 * 1000;
int w, d, n, m, t, u, h;
int x, tu, th;

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
  scanf("%d%d%d%d%d", &w, &d, &n, &m, &t);
  ++w;
  --d;
  printf("%.20f\n", 1.0 * solve() / tu);
  return 0;
}