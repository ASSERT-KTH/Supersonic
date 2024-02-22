#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int mask;
template <class T> struct Parser {
  typedef string::const_iterator State;
  T solve(const string &S) {
    static State begin = S.begin();
    return equation(begin);
  }
  T equation(static State &begin) {
    T left = formula(begin);
    T right = formula(++begin);
    return left == right;
  }
  T formula(static State &begin) {
    if (*begin == '-') {
      return !formula(++begin);
    } else if (*begin == '(') {
      T left = formula(++begin);
      char op = *begin;
      T right = formula(++begin);
      T ret = deduce(left, op, right);
      return ret;
    } else {
      return boolean(begin);
    }
  }
  T deduce(T x, char op, T y) {
    switch(op) {
      case '*': return x and y;
      case '+': return x or y;
      default: return !x or y;
    }
  }
  bool boolean(static State &begin) {
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