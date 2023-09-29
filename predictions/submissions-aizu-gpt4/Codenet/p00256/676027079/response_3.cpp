#include <iostream>
#include <vector>
#include <string>

using ll = long long;
struct S {
  ll y, m, d;
};
struct Ma {
  ll b, ka, t, w, ki;
};
constexpr int M[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

inline bool check(ll y) { return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)); }

S M2S(ll b, ll ka, ll t, ll w, ll ki) {
  ka += b * 20;
  t += ka * 20;
  w += t * 18;
  ki += w * 20;
  S res{2012, 12, 21 + ki};
  while (res.d > 365 + check(res.y + 1))
    res.y++, res.d -= (365 + check(res.y));
  if (res.d == 0) {
    res.m--, res.d = M[res.m - 1] + (check(res.y) && res.m == 2);
  } else {
    res.y++, res.m = 1, res.d -= 31;
    while (res.d > (M[res.m - 1] + (check(res.y) && res.m == 2))) {
      res.d -= (M[res.m - 1] + (check(res.y) && res.m == 2));
      res.m++;
    }
    if (res.d == 0)
      res.m--, res.d = M[res.m - 1] + (check(res.y) && res.m == 2);
  }
  return res;
}

Ma S2M(ll y, ll m, ll d) {
  y -= 2012;
  d = y ? d + 10 : d - 21;
  for (int i = 0; i < m - 1 && y; i++)
    d += (M[i] + (i == 1 && check(y + 2012)));
  d += (--y > 0) ? (365 + check(y + 2012)) * y : 0;
  Ma res;
  d %= 13 * 20 * 20 * 18 * 20;
  res.ki = d % 20;
  res.w = (d / 20) % 18;
  res.t = (d / 360) % 20;
  res.ka = (d / 7200) % 20;
  res.b = d / 144000;
  return res;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::string str;
  while (std::cin >> str && str != "#") {
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
      const S ans = M2S(a[0], a[1], a[2], a[3], a[4]);
      std::cout << ans.y << "." << ans.m << "." << ans.d << "\n";
    } else {
      const Ma ans = S2M(a[0], a[1], a[2]);
      std::cout << ans.b << "." << ans.ka << "." << ans.t << "." << ans.w << "." << ans.ki << "\n";
    }
  }
  return 0;
}