#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define all(a) a.begin(), a.end()
int solve(const vector<string> &s, int n, int &y, int x) {
  if (isdigit(s[y][x]))
    return s[y++][x] - '0';
  char op = s[y][x];
  ++y, ++x;
  vector<int> term;
  while (y < n && (int)s[y].size() > x) {
    term.push_back(solve(s, n, y, x));
  }
  if (op == '+')
    return accumulate(all(term), 0);
  else
    return accumulate(all(term), 1, multiplies<int>());
}
int main(void) {
  int n;
  while (scanf("%d", &n), n) {
    vector<string> s(n);
    rep(i, n) scanf("%s", s[i]);
    int y = 0;
    cout << solve(s, n, y, 0) << endl;
  }
  return 0;
}
