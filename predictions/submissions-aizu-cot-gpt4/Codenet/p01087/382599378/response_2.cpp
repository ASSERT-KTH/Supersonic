#include <iostream>
#include <vector>
#include <numeric>
#include <functional>
#include <cctype>

using namespace std;

int solve(const vector<string> &s, int &y, int x) {
  if (isdigit(s[y][x]))
    return s[y++][x] - '0';
  char op = s[y][x];
  ++y, ++x;
  int result = (op == '+') ? 0 : 1;
  while (y < s.size() && (int)s[y].size() > x) {
    int val = solve(s, y, x);
    if(op == '+')
        result += val;
    else
        result *= val;
  }
  return result;
}

int main(void) {
  int n;
  while (cin >> n, n) {
    vector<string> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];
    int y = 0;
    cout << solve(s, y, 0) << endl;
  }
  return 0;
}