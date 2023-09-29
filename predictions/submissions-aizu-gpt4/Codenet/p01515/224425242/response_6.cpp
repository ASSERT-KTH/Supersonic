#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int mask;
template <class T> struct Parser {
  typedef string::const_iterator State;
  T solve(const string &S) {
    State begin = S.begin();
    return equation(begin);
  }
  T equation(State &begin) {
    T left = formula(begin);
    T right = formula(begin);
    return left == right;
  }
  T formula(State &begin) {
    if (*begin == '(') {
      T left = formula(++begin);
      char op = *begin;
      if (op == '-')
        ++begin;
      T right = formula(++begin);
      return deduce(left, op, right);
    } else if (*begin == '-') {
      return !formula(++begin);
    } else {
      return boolean(begin);
    }
  }
  T deduce(T x, char op, T y) {
    if (op == '*') {
      return x && y;
    } else if (op == '+') {
      return x || y;
    } else {
      return !x || y;
    }
  }
  T boolean(State &begin) {
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
void solve(const string &S) {
  Parser<bool> ps;
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