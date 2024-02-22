#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int mask;

struct Parser {
  typedef string::const_iterator State;
  bool solve(const string& S) {
    State begin = S.begin();
    return equation(begin);
  }

  bool equation(State begin) {
    T left = formula(begin);
    T right;
    if (*begin == '(') {
      begin++;
      right = formula(begin);
    } else {
      right = formula(++begin);
    }
    return left == right;
  }

  T formula(State begin) {
    if (*begin == '(') {
      begin++;
      T left = formula(begin);
      char op = *begin;
      begin++;
      if (op == '-')
        begin++;
      T right = formula(begin);
      begin++;
      T ret = deduce(left, op, right);
      return ret;
    } else if (*begin == '-') {
      begin++;
      return !formula(begin);
    } else {
      return boolean(begin);
    }
  }

  T deduce(T x, char op, T y) {
    switch (op) {
      case '*':
        return x && y;
      case '+':
        return x || y;
      default:
        return !x || y;
    }
  }

  T boolean(State begin) {
    T ret;
    if (*begin == 'T')
      ret = true;
    else if (*begin == 'F')
      ret = false;
    else
      ret = (mask >> (*begin - 'a')) & 1;
    begin++;
    return ret;
  }
};

void solve(const string& S) {
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
  while (cin >> S && S.compare("#") != 0) {
    solve(S);
  }
  return 0;
}