#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int solve(vector<string>& s, int n, int& y, int x) {
  if (isdigit(s[y][x]))
    return s[y++][x] - '0';

  char op = s[y][x];
  ++y, ++x;
  vector<int> term;

  while (y < n && s[y].size() > x) {
    term.push_back(solve(s, n, y, x));
  }

  if (op == '+')
    return accumulate(term.begin(), term.end(), 0);
  else
    return accumulate(term.begin(), term.end(), 1, multiplies<int>());
}

int main() {
  int n;

  while (cin >> n, n) {
    vector<string> s(n);

    for (auto& str : s) {
      cin >> str;
    }

    int y;
    cout << solve(s, n, y, 0) << endl;
  }

  return 0;
}