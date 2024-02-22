#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define all(a) a.begin(), a.end()
int solve(vector<string> &s, int n, int &y, int x) {
  if (s[y][x] >= '0' && s[y][x] <= '9')
    return s[y++][x] - '0';
  char op = s[y][x];
  ++y, ++x;
  vector<int> term;
  term.reserve(s[y].size());
  while (y < n && (int)s[y].size() > x) {
    term.push_back(solve(s, n, y, x));
  }
  if (op == '+')
    return accumulate(all(term), 0);
  else {
    int product = 1;
    for (int num : term)
      product *= num;
    return product;
  }
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