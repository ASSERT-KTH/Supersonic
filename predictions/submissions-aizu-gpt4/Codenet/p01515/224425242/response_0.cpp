#include <iostream>
#include <string>
#include <vector>
using namespace std;

int mask;
template <typename T> struct Parser {
  using State = string::const_iterator;
  T ParseFormula(State &begin) {
    if (*begin == '(') {
      ++begin;
      T left = ParseFormula(begin);
      char op = *begin;
      ++begin;
      if (op == '-')
        ++begin;
      T right = ParseFormula(begin);
      ++begin;
      return Deduce(left, op, right);
    } else if (*begin == '-') {
      ++begin;
      return !ParseFormula(begin);
    } else {
      return Boolean(begin);
    }
  }
  T Deduce(T x, char op, T y) {
    if (op == '*') 
      return x && y;
    else if (op == '+') 
      return x || y;
    else 
      return !x || y;
  }
  T Boolean(State &begin) {
    if (*begin == 'T')
      return true;
    else if (*begin == 'F')
      return false;
    else
      return (mask >> (*begin - 'a')) & 1;
    ++begin;
  }
  T Solve(const string &S) {
    State begin = S.begin();
    return ParseFormula(begin);
  }
};
void solve(string S) {
  Parser<bool> parser;
  for (mask = 0; mask < (1 << 11); ++mask) {
    if (!parser.Solve(S)) {
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