#include <cstdio>
using namespace std;

const int MN = 501 * 1000 * 1000;

int w, d, n, m, t;
int tu, th, x;

int gcd(int a, int b) {
  return __gcd(a, b);
}

int ext_gcd(int a, int b, int &x, int &y) {
  int d = a;
  x = 1; y = 0;
  while (b) {
    int q = a / b;
    int r = a % b;
    a = b;
    b = r;
    int nx = y;
    y = x - q * y;
    x = nx;
  }
  return d;
}

void init() {
  m = t - m % t;
  int u = gcd(t, w + d), h = gcd(t, m);
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
  for (int i = 0; i < th; ++i) {
    if (s < n) {
      res += max(0, (i - w) / tu - l);
      l = i / tu;
    }
    s += x;
    if (s >= th)
      s -= th;
  }
  res += max(0, (t - w) / tu - l);
  return res;
}

int main() {
  scanf("%d %d %d %d %d", &w, &d, &n, &m, &t);
  w++;
  d--;
  printf("%lld\n", (long long)solve());
  return 0;
}