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
    State begin = S.begin();
    return equation(begin);
  }
  T equation(State &begin) {
    T left = formula(begin);
    begin++;
    T right = formula(begin);
    return left == right;
  }
  T formula(State &begin) {
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
    if (op == '*') {
      return x and y;
    } else if (op == '+') {
      return x or y;
    } else {
      return !x or y;
    }
  }
  T boolean(State &begin) {
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
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string S;
  while (cin >> S && S != "#") {
    solve(S);
  }
  return 0;
}
