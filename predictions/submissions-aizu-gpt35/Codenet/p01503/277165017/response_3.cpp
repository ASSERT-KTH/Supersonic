#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

const int MN = 501 * 1000 * 1000;
const int MAX_T = 1000005;
const int MAX_H = 1000005;

int w, d, n, m, t, u, h;
int tu, th;
int x[MAX_H];
int max_i[MAX_T];
int res[MAX_T];

void init() {
  m = t - m % t;
  u = __gcd(t, w + d);
  h = __gcd(t, m);
  tu = t / u;
  th = t / h;
  ll xx, y;
  __gcd(m, t, xx, y);
  x[0] = ((xx % th) + th) % th;
  for (int i = h; i < t; i += h) {
    x[i / h] = x[(i - h) / h] + x[0];
    if (x[i / h] >= th)
      x[i / h] -= th;
  }
}

int solve() {
  init();
  int res = 0;
  int l = 0;
  int s = 0;
  for (int i = 0; i < t; i += h) {
    if (s < n) {
      res += max(0, (i - w) / u - l);
      l = i / u;
    }
    s += x[i / h];
    if (s >= th)
      s -= th;
  }
  res += max(0, (t - w) / u - l);
  return res;
}

int main() {
  scanf("%d%d%d%d%d", &w, &d, &n, &m, &t);
  w++;
  d--;
  printf("%.20f\n", 1.0 * solve() / (t / __gcd(t, w + d)));
  return 0;
}