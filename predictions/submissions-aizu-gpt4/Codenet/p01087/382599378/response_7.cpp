#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
#define rep(i, n) for (int i = 0; i < int(n); ++i)

int solve(vector<string> &s, int n, int &y, int x) {
  if (isdigit(s[y][x])) return s[y++][x] - '0';
  char op = s[y][x];
  ++y, ++x;
  vector<int> term;
  term.reserve(n);
  while (y < n && x < s[y].size()) {
    term.push_back(solve(s, n, y, x));
  }
  if (op == '+') return accumulate(term.begin(), term.end(), 0);
  return accumulate(term.begin(), term.end(), 1, multiplies<int>());
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  while (cin >> n, n) {
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    int y = 0;
    cout << solve(s, n, y, 0) << '\n';
  }
  return 0;
}