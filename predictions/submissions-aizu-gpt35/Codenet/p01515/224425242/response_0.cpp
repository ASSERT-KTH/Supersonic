#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <class T> struct Parser {
  typedef string::const_iterator State;
  T solve(const string &S) {
    State begin = S.begin();
    return equation(begin);
  }
  T equation(State &begin) {
    T left = formula(begin);
    ++begin;  // Use prefix increment instead of postfix increment
    T right = formula(begin);
    return left == right;
  }
  T formula(State &begin) {
    if (*begin == '(') {
      ++begin;  // Use prefix increment instead of postfix increment
      T left = formula(begin);
      char op = *begin;
      ++begin;  // Use prefix increment instead of postfix increment
      if (op == '-')
        ++begin;  // Use prefix increment instead of postfix increment
      T right = formula(begin);
      ++begin;  // Use prefix increment instead of postfix increment
      T ret = deduce(left, op, right);
      return ret;
    } else if (*begin == '-') {
      ++begin;  // Use prefix increment instead of postfix increment
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
    ++begin;  // Use prefix increment instead of postfix increment
    return ret;
  }
};

void solve(const string& S) {
  Parser<bool> ps;
  for (int mask = 0; mask < (1 << 11); ++mask) {  // Declare and increment "mask" inside the loop
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