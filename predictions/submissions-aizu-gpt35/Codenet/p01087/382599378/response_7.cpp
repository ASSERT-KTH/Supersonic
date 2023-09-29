#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < int(n); ++i)

int solve(vector<string> &s, int n, int &y, int x) {
  if (isdigit(s[y][x]))
    return s[y++][x] - '0';
  char op = s[y][x];
  ++y, ++x;
  vector<int> term;
  while (y < n && (int)s[y].size() > x) {
    term.push_back(solve(s, n, y, x));
  }
  int result = 0;
  if (op == '+') {
    for (int c : term) result += c;
  } else {
    result = 1;
    for (int c : term) result *= c;
  }
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  while (cin >> n, n) {
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    int y = 0;
    cout << solve(s, n, y, 0) << '\n';
  }
}
