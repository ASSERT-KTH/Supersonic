#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)

int solve(vector<string> &s, int n, int &y, int x) {
  if (s[y][x] >= '0' && s[y][x] <= '9') {
    int val = s[y][x] - '0';
    y++;
    return val;
  }
  char op = s[y][x];
  ++y, ++x;
  int total = (op == '+') ? 0 : 1;
  while (y < n && (int)s[y].size() > x) {
    int val = solve(s, n, y, x);
    if (op == '+')
      total += val;
    else
      total *= val;
  }
  return total;
}

int main(void) {
  int n;
  while (cin >> n, n) {
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    int y = 0;
    cout << solve(s, n, y, 0) << endl;
  }
  return 0;
}