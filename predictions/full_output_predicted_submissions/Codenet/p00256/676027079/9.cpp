#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct S {
  ll y, m, d;
};
struct Ma {
  ll b, ka, t, w, ki;
};
int M[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool check(ll y) { return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)); }
S M2S(ll b, ll ka, ll t, ll w, ll ki) {
  ka += b * 20;
  t += ka * 20;
  w += t * 18;
  ki += w * 20;
  S res;
  res.y = 2012, res.m = 11, res.d = 21 + ki;
  if (res.d <= 31)
    return res;
  while (res.d / (365 + check(res.y + 1)))
    res.y++, res.d -= (365 + check(res.y));
  if (res.d == 0)
    res.m--, res.d = M[res.m - 1] + (check(res.y) && res.m == 2);
  if (res.d <= 31)
    return res;
  res.y++, res.m = 1, res.d -= 31;
  while (res.d / (M[res.m - 1] + (check(res.y) && res.m == 2))) {
    res.d -= (M[res.m - 1] + (check(res.y) && res.m == 2));
    res.m++;
  }
  if (res.d == 0)
    res.m--, res.d = M[res.m - 1] + (check(res.y) && res.m == 2);
  return res;
}
Ma S2M(ll y, ll m, ll d) {
  y -= 2012;
  if (y)
    d += 10;
  else
  