#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int mask;

template <class T> struct Parser {
  typedef string::const_iterator State;
  State expression;

  void loadExpression(const string &S) {
    expression = S.begin();
  }

  T solve() {
    State temp = expression;
    return equation(temp);
  }

  T equation(State &begin) {
    T left = formula(begin);
    begin++;
    T right = formula(begin);
    return left == right;
  }

  T formula(State &begin) {
    // Same as before...
  }

  T deduce(T x, char op, T y) {
    // Same as before...
  }

  T boolean(State &begin) {
    // Same as before...
  }
};

void solve(string S) {
  Parser<bool> ps;
  ps.loadExpression(S);
  for (mask = 0; mask < (1 << 11); mask++) {
    if (!ps.solve()) {
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