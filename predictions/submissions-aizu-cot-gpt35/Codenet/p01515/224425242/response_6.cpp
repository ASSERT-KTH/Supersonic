#include <iostream>
#include <string>
#include <vector>

template <class T>
struct Parser {
  T solve(const std::string& S, int mask) {
    auto begin = S.begin();
    return equation(begin, mask);
  }

  T equation(typename std::string::const_iterator& begin, int mask) {
    T left = formula(begin, mask);
    ++begin;
    T right = formula(begin, mask);
    return left == right;
  }

  T formula(typename std::string::const_iterator& begin, int mask) {
    if (*begin == '(') {
      ++begin;
      T left = formula(begin, mask);
      char op = *begin;
      ++begin;
      if (op == '-')
        ++begin;
      T right = formula(begin, mask);
      ++begin;
      T ret = deduce(left, op, right);
      return ret;
    } else if (*begin == '-') {
      ++begin;
      return !formula(begin, mask);
    } else {
      return boolean(begin, mask);
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

  T boolean(typename std::string::const_iterator& begin, int mask) {
    T ret;
    if (*begin == 'T')
      ret = true;
    else if (*begin == 'F')
      ret = false;
    else
      ret = (mask >> (*begin - 'a')) & 1;
    ++begin;
    return ret;
  }
};

void solve(const std::string& S, int mask) {
  Parser<bool> ps;
  if (!ps.solve(S, mask)) {
    std::cout << "NO" << std::endl;
  } else {
    std::cout << "YES" << std::endl;
  }
}

int main() {
  std::string S;
  while (std::cin >> S && S != "#") {
    for (int mask = 0; mask < 1; ++mask) {
      solve(S, mask);
    }
  }
  return 0;
}