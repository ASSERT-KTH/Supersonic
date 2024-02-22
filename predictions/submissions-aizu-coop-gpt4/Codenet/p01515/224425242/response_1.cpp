#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

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
      return x and y;
    } else if (op == '+') {
      return x or y;
    } else {
      return !x or y;
    }
  }
  bool boolean(State &begin) {
    bool ret;
    switch(*begin) {
      case 'T':
        ret = true;
        break;
      case 'F':
        ret = false;
        break;
      default:
        ret = (mask >> (*begin - 'a')) & 1;
    }
    begin++;
    return ret;
  }
  int mask = 0;
};

void solve(string S) {
  Parser ps;
  for (ps.mask = 0; ps.mask < (1 << 11); ps.mask++) {
    if (!ps.solve(S)) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}

int main() {
  string S;
  S.reserve(1000);
  while (cin >> S && S != "#") {
    solve(S);
  }
  return 0;
}