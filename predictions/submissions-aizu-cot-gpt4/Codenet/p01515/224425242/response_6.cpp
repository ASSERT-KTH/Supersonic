#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
template <class T> struct Parser {
  typedef string::const_iterator State;
  T solve(const string &S, int mask) {
    State begin = S.begin();
    return equation(begin);
  }
  T equation(State &begin) {
    T left = formula(begin);
    begin++;
    T right = formula(begin);
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
      if (op == '*') {
        return left and right;
      } else if (op == '+') {
        return left or right;
      } else {
        return !left or right;
      }
    } else if (*begin == '-') {
      begin++;
      return !formula(begin, mask);
    } else {
      return boolean(begin, mask);
    }
  }
  T boolean(State &begin, int mask) {
    if (*begin == 'T')
      return 1;
    else if (*begin == 'F')
      return 0;
    else
      return (mask >> (*begin - 'a')) & 1;
    begin++;
  }
};
int main() {
  string S;
  while (cin >> S && S != "#") {
    Parser<bool> ps;
    bool result = true;
    for (int mask = 0; mask < (1 << 11); mask++) {
      if (!ps.solve(S, mask)) {
        result = false;
        break;
      }
    }
    cout << (result ? "YES" : "NO") << endl;
  }
  return 0;
}