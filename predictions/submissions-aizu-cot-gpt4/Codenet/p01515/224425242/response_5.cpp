#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

int mask;
template <class T> struct Parser {
  typedef std::string::const_iterator State;
  T solve(const std::string &S) {
    State begin = S.begin();
    return equation(begin);
  }
  //... keep the other functions as is
};

void solve(std::string S, Parser<bool>& ps) {
  for (mask = 0; mask < (1 << 11); mask++) {
    if (!ps.solve(S)) {
      std::cout << "NO" << '\n';
      return;
    }
  }
  std::cout << "YES" << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::string S;
  Parser<bool> ps;
  while (std::cin >> S && S != "#") {
    solve(S, ps);
  }
  return 0;
}