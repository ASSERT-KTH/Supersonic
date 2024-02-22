#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

struct S {
  ll y, m, d;
};

struct Ma {
  ll b, ka, t, w, ki;
};

bool check(ll y) {
  return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
}

S M2S(ll b, ll ka, ll t, ll w, ll ki) {
  ka += b * 20;
  t += ka * 20;
  w += t * 18;
  ki += w * 20;

  S res;
  res.y = 2012;
  res.d = 21 + ki;

  int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int month = 0;

  while (res.d > monthDays[month] + (month == 1 && check(res.y))) {
    res.d -= monthDays[month] + (month == 1 && check(res.y));
    month++;
  }

  res.m = month + 1;

  if (res.d == 0) {
    month--;
    res.d = monthDays[month] + (month == 1 && check(res.y));
  }

  if (res.d > 31) {
    res.y++;
    res.m = 1;
    res.d -= 31;

    while (res.d > monthDays[month] + (month == 1 && check(res.y))) {
      res.d -= monthDays[month] + (month == 1 && check(res.y));
      month++;
    }

    res.m = month + 1;

    if (res.d == 0) {
      month--;
      res.d = monthDays[month] + (month == 1 && check(res.y));
    }
  }

  return res;
}

Ma S2M(ll y, ll m, ll d) {
  y -= 2012;
  if (y)
    d += 10;
  else
    d -= 21;

  int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  for (int i = 0; i < m - 1; i++)
    d += monthDays[i] + (i == 1 && check(y + 2012));

  y--;

  while (y > 0) {
    d += 365 + check(y + 2012);
    y--;
  }

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
    string str;
    cin >> str;
    if (str == "#")
      break;
    ll a[5], num = 0;
    int idx = 0;

    for (char c : str) {
      if (c == '.') {
        a[idx] = num;
        num = 0;
        idx++;
      } else {
        num = num * 10 + c - '0';
      }
    }

    a[idx] = num;
    idx++;

    if (idx == 5) {
      S ans = M2S(a[0], a[1], a[2], a[3], a[4]);
      cout << ans.y << "." << ans.m << "." << ans.d << endl;
    } else {
      Ma ans = S2M(a[0], a[1], a[2]);
      cout << ans.b << "." << ans.ka << "." << ans.t << "." << ans.w << "." << ans.ki << endl;
    }
  }

  return 0;
}