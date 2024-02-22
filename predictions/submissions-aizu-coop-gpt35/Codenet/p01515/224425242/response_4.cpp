#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

template <class T> struct Parser {
  T solve(const string &S) {
    stack<T> results;
    T result;
    char op;

    for (auto it = S.begin(); it != S.end(); ++it) {
      if (*it == '(') {
        results.push(result);
      } else if (*it == ')') {
        T top = results.top();
        results.pop();
        op = *(it + 1);
        ++it;
        if (op == '-') {
          result = !top;
        } else {
          T right = boolean(++it);
          result = deduce(top, op, right);
        }
      } else if (*it == '-') {
        result = !boolean(++it);
      } else {
        result = boolean(it);
      }
    }

    return result;
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

  T boolean(string::const_iterator &it) {
    T ret;
    if (*it == 'T')
      ret = 1;
    else if (*it == 'F')
      ret = 0;
    else
      ret = (1 << (*it - 'a')) & 1;
    return ret;
  }
};

void solve(string S) {
  Parser<bool> ps;
  for (int mask = 0; mask < (1 << 11); mask++) {
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
    solve(S);
  }
  return 0;
}