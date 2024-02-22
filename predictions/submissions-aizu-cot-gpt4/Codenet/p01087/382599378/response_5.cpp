#include <bits/stdc++.h>
using namespace std;

int solve(vector<string> &s, int n, int &y, int x) {
  if (isdigit(s[y][x]))
    return s[y++][x] - '0';
  char op = s[y][x];
  ++y, ++x;
  int sum = 0, prod = 1;
  while (y < n && (int)s[y].size() > x) {
    int result = solve(s, n, y, x);
    if (op == '+')
        sum += result;
    else
        prod *= result;
  }
  return op == '+' ? sum : prod;
}

int main(void) {
  int n;
  while (cin >> n, n) {
    vector<string> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];
    int y = 0;
    cout << solve(s, n, y, 0) << '\n';
  }
  return 0;
}