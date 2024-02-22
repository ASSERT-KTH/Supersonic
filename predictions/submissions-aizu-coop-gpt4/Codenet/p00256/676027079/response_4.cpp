#include <cstdio>
#define ll long long
struct S {
  ll y, m, d;
};
struct Ma {
  ll b, ka, t, w, ki;
};
int M[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool check(ll y) { return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)); }
S M2S(ll b, ll ka, ll t, ll w, ll ki) {
  // Optimized computation.
  ka += b * 20;
  t += ka * 20;
  w += t * 18;
  ki += w * 20;
  S res = {2012, 12, 21 + ki};
  while (res.d > 365 + check(res.y + 1)) {
    res.y++;
    res.d -= (365 + check(res.y));
  }
  if (res.d > 31) {
    res.y++;
    res.m = 1;
    res.d -= 31;
    while (res.d > (M[res.m - 1] + (check(res.y) && res.m == 2))) {
      res.d -= (M[res.m - 1] + (check(res.y) && res.m == 2));
      res.m++;
    }
  }
  return res;
}
Ma S2M(ll y, ll m, ll d) {
  // Optimized computation.
  y -= 2012;
  d = (y ? d + 10 : d - 21);
  for (int i = 0; i < m - 1 && y; i++)
    d += (M[i] + (i == 1 && check(y + 2012)));
  y--;
  while (y > 0) {
    d += (365 + check(y + 2012));
    y--;
  }
  Ma res;
  d %= 13 * 20 * 20 * 18 * 20;
  res.b = d / (20 * 20 * 18 * 20);
  d %= 20 * 20 * 18 * 20;
  res.ka = d / (20 * 18 * 20);
  d %= 20 * 18 * 20;
  res.t = d / (18 * 20);
  d %= 18 * 20;
  res.w = d / 20;
  res.ki = d % 20;
  return res;
}
int main() {
  char str[50];
  while (scanf("%s", str), str[0] != '#') {
    int a[5], i = 0;
    sscanf(str, "%d.%d.%d.%d.%d", &a[0], &a[1], &a[2], &a[3], &a[4]);
    if (a[3] || a[4]) {
      S ans = M2S(a[0], a[1], a[2], a[3], a[4]);
      printf("%lld.%lld.%lld\n", ans.y, ans.m, ans.d);
    } else {
      Ma ans = S2M(a[0], a[1]);
      printf("%lld.%lld.%lld.%lld.%lld\n", ans.b, ans.ka, ans.t, ans.w, ans.ki);
    }
  }
  return 0;
}