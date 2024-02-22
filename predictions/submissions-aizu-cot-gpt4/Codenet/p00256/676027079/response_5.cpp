#include <iostream>
#include <vector>
#include <string>

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
  S res;
  ki += ((b * 20 + ka) * 20 + t) * 18 * 20 + w;
  res.y = 2012, res.m = 12, res.d = 21 + ki;
  if (res.d > 31) {
    while (res.d / (365 + check(res.y + 1)))
      res.y++, res.d -= (365 + check(res.y));
    res.y++, res.m = 1, res.d -= 31;
    while (res.d / (M[res.m - 1] + (check(res.y) && res.m == 2))) {
      res.d -= (M[res.m - 1] + (check(res.y) && res.m == 2));
      res.m++;
    }
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
    d = (d - 21);
  for (int i = 0; i < m - 1 && y; i++)
    d += (M[i] + (i == 1 && check(y + 2012)));
  y--;
  while (y > 0)
    d += (365 + check(y + 2012)), y--;
  Ma res;
  d %= 13 * 20 * 20 * 18 * 20;
  res.ki = d % 20;
  res.w = (d / 20) % 18;
  res.t = (d / (20*18)) % 20;
  res.ka = (d / (20*18*20)) % 20;
  res.b = d / (20*18*20*20);
  return res;
}

int main() {
  while (!std::cin.eof()) {
    std::string str;
    std::cin >> str;
    std::vector<int> a;
    int i = 0, num = 0;
    while (str[i]) {
      if (str[i] == '.')
        a.push_back(num), num = 0;
      else
        num = num * 10 + str[i] - '0';
      i++;
    }
    a.push_back(num);
    if (a.size() == 5) {
      S ans = M2S(a[0], a[1], a[2], a[3], a[4]);
      std::cout << ans.y << "." << ans.m << "." << ans.d << std::endl;
    } else {
      Ma ans = S2M(a[0], a[1], a[2]);
      std::cout << ans.b << "." << ans.ka << "." << ans.t << "." << ans.w << "."
           << ans.ki << std::endl;
    }
  }
  return 0;
}