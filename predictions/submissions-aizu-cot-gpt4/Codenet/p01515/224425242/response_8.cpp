#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

template <class T> struct Parser {
  typedef std::string::const_iterator State;
  T solve(const std::string &S) {
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
    T ret;
    while(*begin){
      if (*begin == '(') {
        begin++;
        T left = formula(begin);
        char op = *begin;
        begin++;
        if (op == '-')
          begin++;
        T right = formula(begin);
        begin++;
        ret = deduce(left, op, right);
      } else if (*begin == '-') {
        begin++;
        ret = !formula(begin);
      } else {
        ret = boolean(begin);
      }
    }
    return ret;
  }
  T deduce(T x, char op, T y) {
    T ret;
    while(*begin){
      if (op == '*') {
        ret = x and y;
      } else if (op == '+') {
        ret = x or y;
      } else {
        ret = !x or y;
      }
    }
    return ret;
  }
  T boolean(State &begin) {
    T ret;
    while(*begin){
      if (*begin == 'T')
        ret = 1;
      else if (*begin == 'F')
        ret = 0;
      else
        ret = (mask >> (*begin - 'a')) & 1;
      begin++;
    }
    return ret;
  }
};

void solve(std::string S) {
  int mask;
  Parser<bool> ps;
  for (mask = 0; mask < (1 << 11); mask++) {
    if (!ps.solve(S)) {
      std::cout << "NO" << std::endl;
      return;
    }
  }
  std::cout << "YES" << std::endl;
}

int main() {
  std::string S;
  while (std::cin >> S && S != "#") {
    solve(S);
  }
  return 0;
}