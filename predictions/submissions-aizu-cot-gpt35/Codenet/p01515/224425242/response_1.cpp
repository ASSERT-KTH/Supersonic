#include <iostream>
#include <string>
using namespace std;

template <class T>
struct Parser {
  typedef string::const_iterator State;

  T solve(const string &S, int mask) {
    State begin = S.begin();
    return equation(begin, mask);
  }

  T equation(State &begin, int mask) {
    T left = formula(begin, mask);
    begin++;
    T right = formula(begin, mask);
    return left == right;
  }

  T formula(State &begin, int mask) {
    if (*begin == '(') {
      begin++;
      T left = formula(begin, mask);
      char op = *begin;
      begin++;
      if (op == '-')
        begin++;
      T right = formula(begin, mask);
      begin++;
      return deduce(left, op, right);
    } else if (*begin == '-') {
      begin++;
      return !formula(begin, mask);
    } else {
      return boolean(begin, mask);
    }
  }

  T deduce(T x, char op, T y) {
    switch (op) {
      case '*':
        return x and y;
      case '+':
        return x or y;
      default:
        return !x or y;
    }
  }

  T boolean(State &begin, int mask) {
    if (*begin == 'T')
      return 1;
    else if (*begin == 'F')
      return 0;
    else
      return (mask >> (*begin - 'a')) & 1;
    begin++;
  }
};

void solve(string S) {
  Parser<bool> ps;
  for (int mask = 0; mask < (1 << 11); mask++) {
    if (!ps.solve(S, mask)) {
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