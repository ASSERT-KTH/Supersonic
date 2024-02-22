#include <iostream>
#include <vector>
using namespace std;

struct S {
  int y, m, d;
};

struct Ma {
  int b, ka, t, w, ki;
};

int M[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check(int y) {
  return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
}

S M2S(int b, int ka, int t, int w, int ki) {
  ki += w * 20 * 18 * 20 + t * 20 * 18 + ka * 20 + b;
  S res;
  res.y = 2012;
  res.m = 12;
  res.d = 21 + ki;
  if (res.d <= 31)
    return res;
  for (res.y = 2013; res.d > (365 + check(res.y)); res.y++)
    res.d -= (365 + check(res.y));
  if (res.d == 0)
    res.m--, res.d = M[res.m - 1] + (check(res.y) && res.m == 2);
  if (res.d <= 31)
    return res;
  res.y++, res.m = 1, res.d -= 31;
  for (; res.d > (M[res.m - 1] + (check(res.y) && res.m == 2)); res.m++)
    res.d -= (M[res.m - 1] + (check(res.y) && res.m == 2));
  if (res.d == 0)
    res.m--, res.d = M[res.m - 1] + (check(res.y) && res.m == 2);
  return res;
}

Ma S2M(int y, int m, int d) {
  d += (y - 2012) * 365 + (y - 2012) / 4 - (y - 2012) / 100 + (y - 2008) / 400 + 10;
  for (int i = 0; i < m - 1; i++)
    d += M[i] + (i == 1 && check(y));
  Ma res;
  res.ki = d & (13 * 20 * 20 * 18 * 20 - 1);
  res.w = res.ki / (20 * 18 * 20);
  res.ki %= (20 * 18 * 20);
  res.t = res.w / 20;
  res.w %= 20;
  res.ka = res.t / 20;
  res.t %= 20;
  res.b = res.ka / 20;
  res.ka %= 20;
  return res;
}

int main() {
  while (true) {
    string str;
    cin >> str;
    if (str == "#")
      break;
    int a[5];
    int i = 0, num = 0;
    for (char c : str) {
      if (c == '.') {
        a[i++] = num;
        num = 0;
      } else {
        num = num * 10 + c - '0';
      }
    }
    a[i] = num;
    if (i == 4) {
      S ans = M2S(a[0], a[1], a[2], a[3], a[4]);
      cout << ans.y << "." << ans.m << "." << ans.d << endl;
    } else {
      Ma ans = S2M(a[0], a[1], a[2]);
      cout << ans.b << "." << ans.ka << "." << ans.t << "." << ans.w << "." << ans.ki << endl;
    }
  }
  return 0;
}