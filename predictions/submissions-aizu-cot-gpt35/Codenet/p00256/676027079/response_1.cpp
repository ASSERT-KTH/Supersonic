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
  ka += b * 20;
  t += ka * 20;
  w += t * 18;
  ki += w * 20;

  S res;
  res.y = 2012;
  res.m = 12;
  res.d = 21 + ki;

  res.y += res.d / 365;
  res.d %= 365;

  if (check(res.y) && res.d == 60) {
    res.d--;
  }

  for (int i = 0; i < 12; i++) {
    if (res.d <= M[i]) {
      res.m = i + 1;
      res.d -= M[i];
      break;
    }
    res.d -= M[i];
    if (check(res.y) && i == 1) {
      res.d--;
    }
  }

  return res;
}

Ma S2M(int y, int m, int d) {
  y -= 2012;
  d += (y ? 10 : -11);

  for (int i = 0; i < m - 1; i++) {
    d += M[i];
    if (check(y + 2012) && i == 1) {
      d++;
    }
  }

  y--;

  d += y * 365 + y / 4 - y / 100 + y / 400;

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
  while (1) {
    string str;
    cin >> str;
    if (str == "#") {
      break;
    }
    vector<int> a;
    int i = 0, num = 0;
    while (str[i]) {
      if (str[i] == '.') {
        a.push_back(num);
        num = 0;
      } else {
        num = num * 10 + str[i] - '0';
      }
      i++;
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