#include <iostream>

typedef long long ll;

ll gcd(ll a, ll b) {
  while (a != 0) {
    ll temp = a;
    a = b % a;
    b = temp;
  }
  return b;
}

ll ext_gcd(ll a, ll b, ll &x, ll &y) {
  ll xx = 0, yy = 1;
  y = 0;
  x = 1;
  while (b != 0) {
    ll q = a / b;
    ll temp = b;
    b = a % b;
    a = temp;
    temp = xx;
    xx = x - q * xx;
    x = temp;
    temp = yy;
    yy = y - q * yy;
    y = temp;
  }
  return a;
}

int solve(int w, int d, int n, int m, int t) {
  int res = 0;
  int l = 0;
  int th = t / gcd(t, m);
  int u = gcd(t, w + d);
  int x;
  ll xx, y;
  ext_gcd(m, t, xx, y);
  x = ((xx % th) + th) % th;
  
  for (int i = 0; i < t; i += t / gcd(t, m)) {
    if (i < n * x * (t / gcd(t, m)) + l * (t / gcd(t, w + d))) {
      res += (i - w) / u - l;
      l = i / u;
    }
  }
  res += (t - w) / u - l;
  return res;
}

int main() {
  int w, d, n, m, t;
  std::cin >> w >> d >> n >> m >> t;
  w++;
  d--;
  int tu = t / gcd(t, w + d);
  std::cout << 1.0 * solve(w, d, n, m, t) / tu << std::endl;
  return 0;
}