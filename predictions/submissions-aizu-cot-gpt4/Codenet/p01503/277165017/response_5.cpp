#include <iostream>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}

int main() {
  int w, d, n, m, t, u, h;
  int x, tu, th;
  cin >> w >> d >> n >> m >> t;
  w++;
  d--;

  m = t - m % t;
  u = gcd(t, w + d), h = gcd(t, m);
  tu = t / u;
  th = t / h;

  ll xx, y;
  xx = m / gcd(m, t);
  x = ((xx % th) + th) % th;

  int res = 0;
  int l = 0;
  int s = 0;
  th = t / h;
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

  printf("%.20f\n", 1.0 * res / tu);
  return 0;
}