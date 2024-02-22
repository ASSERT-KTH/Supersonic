#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int solve(vector<string> &s, int n, int &y, int x) {
  if (isdigit(s[y][x]))
    return s[y++][x] - '0';
  char op = s[y][x];
  ++y, ++x;
  vector<int> term(n);
  int i = 0;
  while (y < n && (int)s[y].size() > x) {
    term[i++] = solve(s, n, y, x);
  }
  int result = accumulate(term.begin(), term.begin() + i, 0);
  if (op == '+')
    return result;
  else
    return accumulate(term.begin(), term.begin() + i, 1, multiplies<int>());
}

int main(void) {
  int n;
  while (cin >> n, n) {
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
      cin >> s[i];
    }
    int y = 0;
    cout << solve(s, n, y, 0) << endl;
  }
  return 0;
}