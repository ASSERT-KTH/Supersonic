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
    T left, right;
    char op;
    if (*begin == '(') {
      begin++;
      left = formula(begin);
      op = *begin;
      begin++;
      if (op == '-')
        begin++;
      right = formula(begin);
      begin++;
    } else if (*begin == '-') {
      begin++;
      return !formula(begin);
    } else {
      left = (*begin == 'T') ? 1 : (*begin == 'F') ? 0 : (mask >> (*begin - 'a')) & 1;
      begin++;
      op = *begin;
      begin++;
      right = formula(begin);
    }
    if (op == '*') {
      return left and right;
    } else if (op == '+') {
      return left or right;
    } else {
      return !left or right;
    }
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