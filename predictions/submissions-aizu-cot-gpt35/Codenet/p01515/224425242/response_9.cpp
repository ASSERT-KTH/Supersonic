#include <iostream>
#include <string>

template <class T>
struct Parser {
  typedef typename std::string::const_iterator State;
  T solve(const std::string& S) {
    State begin = S.begin();
    return equation(begin);
  }

  T equation(State& begin) {
    T left = formula(begin);
    ++begin;
    T right = formula(begin);
    return left == right;
  }

  T formula(State& begin) {
    if (*begin == '(') {
      ++begin;
      T left = formula(begin);
      char op = *begin;
      ++begin;
      if (op == '-')
        ++begin;
      T right = formula(begin);
      ++begin;
      T ret = deduce(left, op, right);
      return ret;
    } else if (*begin == '-' || *begin == '!') {
      ++begin;
      return !formula(begin);
    } else {
      return boolean(begin);
    }
  }

  T deduce(T x, char op, T y) {
    if (op == '*') {
      return x & y;
    } else if (op == '+') {
      return x | y;
    } else {
      return !x | y;
    }
  }

  T boolean(State& begin) {
    T ret;
    if (*begin == 'T')
      ret = 1;
    else if (*begin == 'F')
      ret = 0;
    else
      ret = (mask >> (*begin - 'a')) & 1;
    ++begin;
    return ret;
  }
};

void solve(const std::string& S) {
  Parser<bool> ps;
  for (int mask = 0; mask < (1 << 11); ++mask) {
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