#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int mask;

template <class T>
struct Parser {
  typedef vector<char>::const_iterator State;
  typedef pair<State, T> Memo;
  vector<vector<Memo>> memo;

  T solve(const vector<char>& S) {
    memo.assign(S.size(), vector<Memo>(1 << 11, Memo(S.end(), false)));
    return equation(S.begin());
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
      return x and y;
    } else if (op == '+') {
      return x or y;
    } else {
      return !x or y;
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

void solve(const vector<char>& S) {
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
    vector<char> expression(S.begin(), S.end());
    solve(expression);
  }
  return 0;
}