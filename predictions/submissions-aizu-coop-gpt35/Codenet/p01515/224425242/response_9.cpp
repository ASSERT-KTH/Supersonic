#include <iostream>

template <class T>
struct Parser {
  typedef const char* State;

  T solve(const char* S) {
    State begin = S;
    return equation(begin);
  }

  T equation(State& begin) {
    T left = formula(begin);
    begin++;
    T right = formula(begin);
    return left == right;
  }

  T formula(State& begin) {
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
    begin++;
    return ret;
  }
};

void solve(const char* S) {
  Parser<bool> ps;
  for (int mask = 0; mask < (1 << 11); mask++) {
    if (!ps.solve(S)) {
      std::cout << "NO" << std::endl;
      return;
    }
  }
  std::cout << "YES" << std::endl;
}

int main() {
  const char* S;
  while (std::cin >> S && S[0] != '#') {
    solve(S);
  }
  return 0;
}