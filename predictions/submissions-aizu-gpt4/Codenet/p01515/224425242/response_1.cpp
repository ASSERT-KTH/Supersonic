#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef string::const_iterator State;

bool deduce(bool x, char op, bool y) {
    if (op == '*') {
      return x and y;
    } else if (op == '+') {
      return x or y;
    } else {
      return !x or y;
    }
}

bool equation(State &begin, int mask) {
    bool left = formula(begin, mask);
    begin++;
    bool right = formula(begin, mask);
    return left == right;
}

bool formula(State &begin, int mask) {
    if (*begin == '(') {
      begin++;
      bool left = formula(begin, mask);
      char op = *begin;
      begin++;
      if (op == '-')
        begin++;
      bool right = formula(begin, mask);
      begin++;
      bool ret = deduce(left, op, right);
      return ret;
    } else if (*begin == '-') {
      begin++;
      return !formula(begin, mask);
    } else {
      return boolean(begin, mask);
    }
}

bool boolean(State &begin, int mask) {
    bool ret;
    if (*begin == 'T')
      ret = 1;
    else if (*begin == 'F')
      ret = 0;
    else
      ret = (mask >> (*begin - 'a')) & 1;
    begin++;
    return ret;
}

void solve(const string &S) {
  for (int mask = 0; mask < (1 << 11); mask++) {
    State begin = S.begin();
    if (!equation(begin, mask)) {
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