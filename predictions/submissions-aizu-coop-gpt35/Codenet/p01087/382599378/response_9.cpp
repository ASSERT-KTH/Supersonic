#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define all(a) a.begin(), a.end()

int solve(const vector<string> &s, int n, int y, int x) {
  if (isdigit(s[y][x]))
    return s[y][x] - '0';
  char op = s[y][x];
  int stringSize = s[y].size();
  ++y, ++x;
  vector<int> term(stringSize - x);
  term.reserve(stringSize - x);
  for (int i = 0; i < term.size(); ++i) {
    term[i] = solve(s, n, y, x);
  }
  if (op == '+') {
    int sum = 0;
    for (int i = 0; i < term.size(); ++i) {
      sum += term[i];
    }
    return sum;
  } else {
    int product = 1;
    for (int i = 0; i < term.size(); ++i) {
      product *= term[i];
    }
    return product;
  }
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