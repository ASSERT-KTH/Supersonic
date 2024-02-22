#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <functional>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::accumulate;
using std::multiplies;

int solve(vector<string> &s, int n, int &y, int x) {
  if (std::isdigit(s[y][x]))
    return s[y++][x] - '0';
  char op = s[y][x];
  ++y, ++x;
  int result = (op == '+') ? 0 : 1;
  while (y < n) {
    int term = solve(s, n, y, x);
    if (op == '+')
      result += term;
    else
      result *= term;
  }
  return result;
}

int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  while (cin >> n, n) {
    vector<string> s(n);
    for (int i = 0; i < n; ++i)
      cin >> s[i];
    int y = 0;
    cout << solve(s, n, y, 0) << endl;
  }
  return 0;
}