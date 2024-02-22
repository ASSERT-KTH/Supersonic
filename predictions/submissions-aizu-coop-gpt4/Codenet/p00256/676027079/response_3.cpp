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
  res.y = 2012, res.m = 12, res.d = 21 + ki;
  if (res.d <= 31)
    return res;
  bool isLeap;
  while (res.d / (365 + (isLeap = check(res.y + 1))))
    res.y++, res.d -= (365 + isLeap);
  if (res.d == 0)
    res.m--, res.d = M[res.m - 1] + (isLeap && res.m == 2);
  if (res.d <= 31)
    return res;
  res.y++, res.m = 1, res.d -= 31;
  while (res.d / (M[res.m - 1] + (isLeap = check(res.y) && res.m == 2))) {
    res.d -= (M[res.m - 1] + isLeap);
    res.m++;
  }
  if (res.d == 0)
    res.m--, res.d = M[res.m - 1] + (isLeap && res.m == 2);
  return res;
}

Ma S2M(ll y, ll m, ll d) {
  y -= 2012;
  if (y)
    d += 10;
  else
    d = (d - 21);
  for (int i = 0; i < m - 1 && y; i++)
    d += (M[i] + (i == 1 && check(y + 2012)));
  y--;
  while (y > 0)
    d += (365 + check(y + 2012)), y--;
  Ma res;
  d %= 13 * 20 * 20 * 18 * 20;
  res.ki = d;
  res.w = res.ki / 20;
  res.ki %= 20;
  res.t = res.w / 18;
  res.w %= 18;
  res.ka = res.t / 20;
  res.t %= 20;
  res.b = res.ka / 20;
  res.ka %= 20;
  return res;
}

int main() {
  while (1) {
    ll a[5];
    char ch;
    int i = 0, num = 0, count = 0;
    while (cin >> ch && ch != '#') {
      if (ch == '.') {
        a[count++] = num, num = 0;
      } else {
        num = num * 10 + ch - '0';
      }
      i++;
    }
    if (ch == '#') {
      break;
    }
    a[count] = num;

    if (count == 4) {
      S ans = M2S(a[0], a[1], a[2], a[3], a[4]);
      cout << ans.y << "." << ans.m << "." << ans.d << endl;
    } else {
      Ma ans = S2M(a[0], a[1], a[2]);
      cout << ans.b << "." << ans.ka << "." << ans.t << "." << ans.w << "." << ans.ki << endl;
    }
  }
  return 0;
}