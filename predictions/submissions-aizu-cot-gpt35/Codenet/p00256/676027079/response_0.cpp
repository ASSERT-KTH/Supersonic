#include <iostream>
#include <vector>
using namespace std;

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
  ki += (w * 18 + t * 18 * 20 + ka * 20 * 20 + b * 20 * 20 * 20);
  S res;
  res.y = 2012 + ki / (365 + check(2012 + ki / (365 + check(2012)))));
  ki %= (365 + check(res.y));
  res.m = 1;
  while (ki >= M[res.m - 1] + (check(res.y) && res.m == 2)) {
    ki -= (M[res.m - 1] + (check(res.y) && res.m == 2));
    res.m++;
  }
  res.d = ki + 1;
  return res;
}

Ma S2M(int y, int m, int d) {
  d += (m - 1) * 20;
  for (int i = y - 2012; i > 0; i--) {
    d += (365 + check(2012 + i - 1));
  }
  Ma res;
  res.ki = d % (13 * 20 * 20 * 18 * 20);
  d /= 20;
  res.w = d % 18;
  d /= 18;
  res.t = d % 20;
  d /= 20;
  res.ka = d % 20;
  d /= 20;
  res.b = d;
  return res;
}

int main() {
  while (true) {
    string str;
    cin >> str;
    if (str == "#")
      break;
    vector<int> a;
    int num = 0;
    for (char c : str) {
      if (c == '.') {
        a.push_back(num);
        num = 0;
      } else {
        num = num * 10 + (c - '0');
      }
    }
    a.push_back(num);
    if (a.size() == 5) {
      S ans = M2S(a[0], a[1], a[2], a[3], a[4]);
      cout << ans.y << "." << ans.m << "." << ans.d << endl;
    } else {
      Ma ans = S2M(a[0], a[1], a[2]);
      cout << ans.b << "." << ans.ka << "." << ans.t << "." << ans.w << "."
           << ans.ki << endl;
    }
  }
  return 0;
}