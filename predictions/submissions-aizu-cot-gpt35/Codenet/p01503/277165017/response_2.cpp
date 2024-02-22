#include <cstdio>
#include <iostream>
using namespace std;

int w, d, n, m, t, u, h;
int x, tu, th;

int gcd(int a, int b) {
  if (!a)
    return b;
  return gcd(b % a, a);
}

int ext_gcd(int a, int b, int &x, int &y) {
  int d = a;
  if (b) {
    d = ext_gcd(b, a % b, y, x);
    y -= a / b * x;
  } else {
    x = 1;
    y = 0;
  }
  return d;
}

void init() {
  m = t - m % t;
  u = gcd(t, w + d);
  h = gcd(t, m);
  tu = t / u;
  th = t / h;
  int xx, y;
  ext_gcd(m, t, xx, y);
  x = ((xx % th) + th) % th;
}

int solve() {
  init();
  int res = 0;
  int l = 0;
  int s = 0;
  int th_val = t / h;
  for (int i = 0; i < t; i += h) {
    if (s < n) {
      int temp = (i - w) / u - l;
      if (temp > 0)
        res += temp;
      l = i / u;
    }
    s += x;
    if (s >= th_val)
      s -= th_val;
  }
  int temp = (t - w) / u - l;
  if (temp > 0)
    res += temp;
  return res;
}

int main() {
  cin >> w >> d >> n >> m >> t;
  w++;
  d--;
  printf("%.20f\n", 1.0 * solve() / tu);
  return 0;
}