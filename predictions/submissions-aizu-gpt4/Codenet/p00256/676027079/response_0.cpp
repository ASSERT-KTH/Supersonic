#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
struct S {
  ll y, m, d;
};
struct Ma {
  ll b, ka, t, w, ki;
};

constexpr int M[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

inline bool check(ll y) { 
    return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)); 
}

S M2S(ll b, ll ka, ll t, ll w, ll ki) {
  ka += b * 20;
  t += ka * 20;
  w += t * 18;
  ki += w * 20;
  S res;
  res.y = 2012, res.m = 12, res.d = 21 + ki;
  while (res.d > 365 + check(res.y + 1))
    res.y++, res.d -= (365 + check(res.y));
  for(res.m = 1; res.d > M[res.m - 1] + (check(res.y) && res.m == 2); res.m++)
    res.d -= (M[res.m - 1] + (check(res.y) && res.m == 2));
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
  for(y--; y > 0; y--)
    d += (365 + check(y + 2012));
  Ma res;
  d %= 13 * 20 * 20 * 18 * 20;
  res.ki = d % 20;
  res.w = (d /= 20) % 18;
  res.t = (d /= 18) % 20;
  res.ka = (d /= 20) % 20;
  res.b = d / 20;
  return res;
}

int main() {
  while (1) {
    string str;
    cin >> str;
    if (str == "#")
      break;
    vector<int> a;
    int num = 0;
    for(auto c : str) {
      if (c == '.') {
        a.push_back(num), num = 0;
      } else {
        num = num * 10 + c - '0';
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