#include <cstdio>
#include <iostream>

int gcd(int a, int b) {
  while (a) {
    int temp = a;
    a = b % a;
    b = temp;
  }
  return b;
}

int solve(int w, int d, int n, int m, int t) {
  int res = 0;
  int l = 0;
  int s = 0;
  int th = t / gcd(t, m);
  int u = gcd(t, w + d);
  int x = ((m % t) + t) % t;
  
  for (int i = 0; i < t; i += t / gcd(t, m)) {
    if (s < n) {
      res += (i - w) / u - l > 0 ? (i - w) / u - l : 0;
      l = i / u;
    }
    s += x;
    if (s >= th)
      s -= th;
  }
  
  res += (t - w) / u - l > 0 ? (t - w) / u - l : 0;
  return res;
}

int main() {
  int w, d, n, m, t;
  std::cin >> w >> d >> n >> m >> t;
  w++;
  d--;
  
  int tu = t / gcd(t, w + d);
  printf("%.20f\n", 1.0 * solve(w, d, n, m, t) * 1.0 / tu);
  return 0;
}