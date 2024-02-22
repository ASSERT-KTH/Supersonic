#include <iostream>
#include <array>
#include <vector>
#include <sstream>

struct S {
  int y, m, d;
};

struct Ma {
  int b, ka, t, w, ki;
};

bool check(int y) {
  return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
}

S M2S(int b, int ka, int t, int w, int ki) {
  std::array<int, 12> M = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  int sum = ki + w * 20 + t * 18 + ka * 20 + b * 20 * 20;
  S res;
  res.y = 2012;
  res.m = 12;
  res.d = 21 + sum;

  if (res.d <= 31)
    return res;

  while (res.d / (365 + check(res.y + 1))) {
    res.y++;
    res.d -= (365 + check(res.y));
  }

  if (res.d == 0) {
    res.m--;
    res.d = M[res.m - 1] + (check(res.y) && res.m == 2);
  }

  if (res.d <= 31)
    return res;

  res.y++;
  res.m = 1;
  res.d -= 31;

  while (res.d / (M[res.m - 1] + (check(res.y) && res.m == 2))) {
    res.d -= (M[res.m - 1] + (check(res.y) && res.m == 2));
    res.m++;
  }

  if (res.d == 0) {
    res.m--;
    res.d = M[res.m - 1] + (check(res.y) && res.m == 2);
  }

  return res;
}

Ma S2M(int y, int m, int d) {
  y -= 2012;

  if (y)
    d += 10;
  else
    d = (d - 21);

  std::array<int, 12> M = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  for (int i = 0; i < m - 1 && y; i++) {
    d += (M[i] + (i == 1 && check(y + 2012)));
  }

  y--;

  while (y > 0) {
    d += (365 + check(y + 2012));
    y--;
  }

  Ma res;
  res.ki = d % (13 * 20 * 20 * 18 * 20);
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
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  std::vector<int> a;
  std::string str;

  while (std::cin >> str && str != "#") {
    std::stringstream ss(str);
    int num;

    while (ss >> num)
      a.push_back(num);

    if (a.size() == 5) {
      S ans = M2S(a[0], a[1], a[2], a[3], a[4]);
      std::cout << ans.y << "." << ans.m << "." << ans.d << "\n";
    } else {
      Ma ans = S2M(a[0], a[1], a[2]);
      std::cout << ans.b << "." << ans.ka << "." << ans.t << "." << ans.w << "." << ans.ki << "\n";
    }

    a.clear();
  }

  return 0;
}