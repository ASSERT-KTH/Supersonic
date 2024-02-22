#include <iostream>
#include <string>

template <class T>
struct Parser {
  T solve(const std::string& S) {
    auto begin = S.begin();
    return equation(begin);
  }

  T equation(typename std::string::const_iterator& begin) {
    T left = formula(begin);
    formula(begin);
    T right = formula(begin);
    return left == right;
  }

  T formula(typename std::string::const_iterator& begin) {
    if (*begin == '(') {
      ++begin;
      T left = formula(begin);
      char op = *begin;
      ++begin;
      if (op == '-') {
        ++begin;
      }
      T right = formula(begin);
      ++begin;
      return deduce(left, op, right);
    } else if (*begin == '-' || *begin == 'T' || *begin == 'F') {
      bool negate = (*begin == '-');
      if (negate) {
        ++begin;
      }
      T result = formula(begin);
      if (negate) {
        return !result;
      } else {
        return result;
      }
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

  T boolean(typename std::string::const_iterator& begin) {
    if (*begin == 'T') {
      ++begin;
      return true;
    } else if (*begin == 'F') {
      ++begin;
      return false;
    } else {
      return (mask >> (*begin - 'a')) & 1;
    }
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
}