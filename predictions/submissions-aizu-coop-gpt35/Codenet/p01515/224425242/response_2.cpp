#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int mask;

template <class T>
struct Parser {
  typedef string::const_iterator State;
  T solve(const string& S) {
    State begin = S.begin();
    return equation(begin);
  }

  T equation(State& begin) {
    T left = formula(begin);
    begin++;
    T right = formula(begin);
    return left == right;
  }

  T formula(State& begin) {
    T left = boolean(begin);
    while (begin != S.end() && (*begin == '*' || *begin == '+')) {
      char op = *begin;
      begin++;
      T right = boolean(begin);
      left = deduce(left, op, right);
    }
    return left;
  }

  T deduce(T x, char op, T y) {
    switch (op) {
      case '*':
        return x & y;
      case '+':
        return x | y;
      default:
        return ~(x | y);
    }
  }

  T boolean(State& begin) {
    static const T lookup[] = {0, 1, 0};  // 'F', 'T', variable
    T ret = lookup[*begin - 'F'];
    if (ret == 0)
      ret = (mask >> (*begin - 'a')) & 1;
    begin++;
    return ret;
  }
};

void solve(const string& S) {
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