#include <iostream>

typedef long long ll;

ll gcd(ll a, ll b) {
  while (a) {
    ll temp = a;
    a = b % a;
    b = temp;
  }
  return b;
}

int solve(int w, int d, int n, int m, int t) {
  int res = 0;
  int l = 0;
  int s = 0;
  int tu = t / gcd(t, w + d);
  int th = t / gcd(t, m);

  int x, u, h;
  ll xx, y;
  ll d1 = gcd(m, t, xx, y);
  x = ((xx % th) + th) % th;
  u = t / d1;
  h = t / gcd(t, m);

  for (int i = 0; i < t; i += h) {
    if (s < n) {
      res += std::max(0, (i - w) / u - l);
      l = i / u;
    }
    s += x;
    if (s >= th)
      s -= th;
  }
  res += std::max(0, (t - w) / u - l);
  return res;
}

int main() {
  int w, d, n, m, t;
  std::cin >> w >> d >> n >> m >> t;
  w++;
  d--;
  std::cout << solve(w, d, n, m, t) / (t / gcd(t, w + d)) << std::endl;
  return 0;
}