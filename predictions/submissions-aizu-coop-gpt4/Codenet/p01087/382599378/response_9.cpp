#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < int(n); ++i)

int solve(vector<string> &s, int n, int &y, int x) {
  if (isdigit(s[y][x]))
    return s[y++][x] - '0';
  char op = s[y][x];
  ++y, ++x;
  int result = (op == '+') ? 0 : 1;  // Initialize result
  while (y < n && (int)s[y].size() > x) {
    int term = solve(s, n, y, x);
    if(op == '+')
      result += term;  // Add term to result
    else
      result *= term;  // Multiply term with result
  }
  return result;
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