#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int mask;
struct Parser {
  typedef string::const_iterator State;
  bool solve(const string &S) {
    State begin = S.begin();
    return equation(begin);
  }
  bool equation(State &begin) {
    bool left = formula(begin);
    begin++;
    bool right = formula(begin);
    return left == right;
  }
  bool formula(State &begin) {
    if (*begin == '(') {
      begin++;
      bool left = formula(begin);
      char op = *begin;
      begin++;
      if (op == '-')
        begin++;
      bool right = formula(begin);
      begin++;
      bool ret = deduce(left, op, right);
      return ret;
    } else if (*begin == '-') {
      begin++;
      return !formula(begin);
    } else {
      return boolean(begin);
    }
  }
  bool deduce(bool x, char op, bool y) {
    if (op == '*') {
      return x & y;
    } else if (op == '+') {
      return x | y;
    } else {
      return !x | y;
    }
  }
  bool boolean(State &begin) {
    bool ret;
    if (*begin == 'T')
      ret = 1;
    else if (*begin == 'F')
      ret = 0;
    else
      ret = (mask >> (*begin - 'a')) & 1;
    begin++;
    return ret;
  }
};
void solve(string S) {
  Parser ps;
  for (mask = 0; mask < (1 << 11); mask++) {
    if (!ps.solve(S)) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}
int main() {
  string S;
  while (cin >> S && S != "#") {
    solve(S);
  }
  return 0;
}