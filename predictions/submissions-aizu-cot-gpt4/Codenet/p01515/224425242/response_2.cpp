#include <cstdio>
#include <algorithm>
#include <cctype>
#include <string>
#include <vector>

using namespace std;

template <class T> struct Parser {
  typedef string::const_iterator State;
  T solve(const string &S, int &mask) {
    State begin = S.begin();
    return equation(begin);
  }
  T equation(State &begin) {
    T left = formula(begin);
    T right = formula(begin);
    return left == right;
  }
  T formula(State &begin) {
    if (*begin == '(') {
      T left = formula(++begin);
      char op = *begin;
      T right;
      if (op == '-')
        right = formula(++begin);
      else
        right = formula(begin);
      T ret = deduce(left, op, right);
      return ret;
    } else if (*begin == '-') {
      return !formula(++begin);
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

void solve(const string &S) {
  Parser<bool> ps;
  for (int mask = 0; mask < (1 << 11); mask++) {
    if (!ps.solve(S, mask)) {
      printf("NO\n");
      return;
    }
  }
  printf("YES\n");
}

int main() {
  string S;
  S.reserve(1000);
  while (scanf("%s", &S[0]) && S != "#") {
    solve(S);
  }
  return 0;
}