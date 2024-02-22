#include <cstdio>

int gcd(int a, int b) {
  while (a != 0) {
    int temp = a;
    a = b % a;
    b = temp;
  }
  return b;
}

int ext_gcd(int a, int b, int &x, int &y) {
  int d = a;
  int xx = 1, yy = 0;
  while (b != 0) {
    int q = a / b;
    int t = b;
    b = a % b;
    a = t;
    t = xx;
    xx = x - q * xx;
    x = t;
    t = yy;
    yy = y - q * yy;
    y = t;
  }
  return d;
}

int solve(int w, int d, int n, int m, int t) {
  int res = 0;
  int l = 0;
  int s = 0;
  int h = gcd(t, m);
  int th = t / h;
  for (int i = 0; i < t; i += h) {
    if (s < n) {
      res += (i - w) / (gcd(t, w + d) * th) - l;
      l = i / (gcd(t, w + d) * th);
    }
    s += ((ext_gcd(m, t, l, s) % th) + th) % th;
  }
  res += (t - w) / (gcd(t, w + d) * th) - l;
  return res;
}

int main() {
  int w, d, n, m, t;
  scanf("%d %d %d %d %d", &w, &d, &n, &m, &t);
  w++;
  d--;
  int tu = t / gcd(t, w + d);
  printf("%.20f\n", 1.0 * solve(w, d, n, m, t) / tu);
  return 0;
}