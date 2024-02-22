#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < int(n); ++i)

int solve(vector<string> &s, int n, int &y, int x) {
  if (isdigit(s[y][x]))
    return s[y++][x] - '0';
  char op = s[y][x];
  ++y; ++x;
  int sum = 0, product = 1;
  if (y < n && s[y].size() > x) {
    if(op == '+')
      sum += solve(s, n, y, x);
    else
      product *= solve(s, n, y, x);
  }
  if (op == '+')
    return sum;
  else
    return product;
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