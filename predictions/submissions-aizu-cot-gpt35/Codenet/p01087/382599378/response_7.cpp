#include <iostream>
#include <vector>
using namespace std;

int solve(vector<string>& s, int n, int x) {
  int y = 0;
  vector<int> term;
  while (y < n && (int)s[y].size() > x) {
    if (isdigit(s[y][x]))
      term.push_back(s[y][x] - '0');
    else {
      char op = s[y][x];
      ++x;
      int term_result = 0;
      while (y < n && (int)s[y].size() > x) {
        term_result += solve(s, n, x);
        ++y;
      }
      if (op == '+')
        term.push_back(term_result);
      else
        term.push_back(term_result + 1);
    }
  }
  
  int result = 0;
  for (int t : term) {
    result += t;
  }
  return result;
}

int main() {
  int n;
  while (scanf("%d", &n), n) {
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
      cin >> s[i];
    }
    cout << solve(s, n, 0) << endl;
  }
  return 0;
}