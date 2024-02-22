#include <iostream>
#include <functional>
#include <string>
using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)

int solve(const string* s, int n, int &y, int x) {
  if (isdigit(s[y][x]))
    return s[y++][x] - '0';
  char op = s[y][x];
  ++y, ++x;
  int result = (op == '+') ? 0 : 1;
  while (y < n && (int)s[y].size() > x) {
    int val = solve(s, n, y, x);
    if (op == '+')
        result += val;
    else
        result *= val;
  }
  return result;
}

int main(void) {
  int n;
  while (cin >> n, n) {
    string s[n];
    rep(i, n) cin >> s[i];
    int y = 0;
    cout << solve(s, n, y, 0) << endl;
  }
  return 0;
}