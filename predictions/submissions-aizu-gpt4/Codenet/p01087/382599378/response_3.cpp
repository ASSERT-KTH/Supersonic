#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define all(a) a.begin(), a.end()
vector<vector<int>> cache;
int solve(vector<string> &s, int n, int &y, int x) {
  if (cache[y][x] != -1)
    return cache[y][x];
  if (isdigit(s[y][x]))
    return cache[y][x] = s[y++][x] - '0';
  char op = s[y][x];
  ++y, ++x;
  vector<int> term;
  while (y < n && (int)s[y].size() > x) {
    term.push_back(solve(s, n, y, x));
  }
  if (op == '+')
    return cache[y][x] = accumulate(all(term), 0);
  else
    return cache[y][x] = accumulate(all(term), 1, multiplies<int>());
}
int main(void) {
  int n;
  while (cin >> n, n) {
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    cache.assign(n, vector<int>(s[0].size(), -1));
    int y = 0;
    cout << solve(s, n, y, 0) << endl;
  }
  return 0;
}