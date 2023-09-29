#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int mask;
template <class T> struct Parser {
  typedef string::const_iterator State;
  T solve(State &begin, const State &end) {
    return equation(begin, end);
  }
  T equation(State &begin, const State &end) {
    T left = formula(begin, end);
    ++begin;
    T right = formula(begin, end);
    return left == right;
  }
  T formula(State &begin, const State &end) {
    if (*begin == '(') {
      ++begin;
      T left = formula(begin, end);
      char op = *begin;
      ++begin;
      if (op == '-')
        ++begin;
      T right = formula(begin, end);
      ++begin;
      return deduce(left, op, right);
    } else if (*begin == '-') {
      ++begin;
      return !formula(begin, end);
    } else {
      return boolean(begin, end);
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
  T boolean(State &begin, const State &end) {
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
void solve(const string &S) {
  Parser<bool> ps;
  const auto n = S.size();
  for (mask = 0; mask < (1 << 11); ++mask) {
    auto begin = S.begin();
    const auto end = S.end();
    if (!ps.solve(begin, end)) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string S;
  while (cin >> S && S != "#") {
    solve(S);
  }
  return 0;
}