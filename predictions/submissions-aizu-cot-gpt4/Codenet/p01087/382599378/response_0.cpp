#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace std;

int solve(vector<string> &s, int n, int &y, int x, vector<int>& term) {
  if (isdigit(s[y][x]))
    return s[y++][x] - '0';
  char op = s[y][x];
  ++y, ++x;
  term.clear();
  while (y < n && (int)s[y].size() > x) {
    term.push_back(solve(s, n, y, x, term));
  }
  if (op == '+')
    return accumulate(term.begin(), term.end(), 0);
  else
    return accumulate(term.begin(), term.end(), 1, multiplies<int>());
}

int main(void) {
  int n;
  while (cin >> n, n) {
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    int y = 0;
    vector<int> term;
    cout << solve(s, n, y, 0, term) << endl;
  }
  return 0;
}