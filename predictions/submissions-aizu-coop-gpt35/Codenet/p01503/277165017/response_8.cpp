#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

ll gcd(ll a, ll b) {
  while (a) {
    ll temp = a;
    a = b % a;
    b = temp;
  }
  return b;
}

ll ext_gcd(ll a, ll b, ll &x, ll &y) {
  ll xx = 1, yy = 0;
  while (b) {
    ll q = a / b;
    ll t = b;
    b = a % b;
    a = t;
    t = xx;
    xx = x - q * xx;
    x = t;
    t = yy;
    yy = y - q * yy;
    y = t;
  }
  return a;
}

const int MN = 501 * 1000 * 1000;

int w, d, n, m, t, u, h;
int x, tu, th;

void init() {
  m = t - m % t;
  u = gcd(t, w + d);
  h = gcd(t, m);
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
  int numIterations = t / h;
  
  int initialL = (w / u) - (w % u == 0);
  if (initialL < 0) initialL = 0;
  res += initialL;
  
  s = (initialL * x) % numIterations;
  
  for (int i = h; i < t; i += h) {
    s += x;
    if (s >= numIterations) s -= numIterations;
    if (s < n) res++;
  }
  
  int finalL = (t - w) / u;
  if (finalL > initialL) res += finalL - initialL;
  
  return res;
}

int main() {
  cin >> w >> d >> n >> m >> t;
  w++;
  d--;
  printf("%.20f\n", 1.0 * solve() / tu);
  return 0;
}