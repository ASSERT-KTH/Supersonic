#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <class T>
struct Parser {
  typedef string::const_iterator State;
  T solve(const string &S, int mask) {
    State begin = S.begin();
    return equation(begin, mask);
  }

  T equation(State &begin, int mask) {
    T left = formula(begin, mask);
    begin++;
    T right = formula(begin, mask);
    return left == right;
  }

  T formula(State &begin, int mask) {
    if (*begin == '(') {
      begin++;
      T left = formula(begin, mask);
      char op = *begin;
      begin++;
      if (op == '-')
        begin++;
      T right = formula(begin, mask);
      begin++;
      T ret = deduce(left, op, right);
      return ret;
    } else if (*begin == '-') {
      begin++;
      return !formula(begin, mask);
    } else {
      return boolean(begin, mask);
    }
  }

  T deduce(T x, char op, T y) {
    if (op == '*') {
      return x and y;
    } else if (op == '+') {
      return x or y;
    } else {
      return !x or y;
    }
  }

  T boolean(State &begin, int mask) {
    T ret;
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

bool solve(const string &S) {
  for (int mask = 0; mask < (1 << 11); mask++) {
    Parser<bool> ps;
    if (!ps.solve(S, mask)) {
      return false;
    }
  }
  return true;
}

int main() {
  string S;
  while (cin >> S && S != "#") {
    if (solve(S)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}