#include <iostream>

int gcd(int a, int b) {
  if (!a)
    return b;
  return gcd(b % a, a);
}

int solve(int w, int d, int n, int m, int t) {
  int m_mod_t = t - m % t;
  int u = gcd(t, w + d);
  int h = gcd(t, m_mod_t);
  int res = 0;
  int l = 0;
  int th = t / h;
  int x = ((m_mod_t % th) + th) % th;

  for (int i = 0; i < t; i += h) {
    if (i / u > l) {
      res += (i - w) / u - l;
      l = i / u;
    }
    l += x;
    if (l >= th)
      l -= th;
  }

  res += (t - w) / u - l;
  return res;
}

int main() {
  int w, d, n, m, t;
  std::cin >> w >> d >> n >> m >> t;
  w++;
  d--;
  int result = solve(w, d, n, m, t);
  std::cout << result << std::endl;
  return 0;
}