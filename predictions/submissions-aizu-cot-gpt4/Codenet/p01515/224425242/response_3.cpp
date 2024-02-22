#include <iostream>
#include <string>
using namespace std;
int mask;

template <class T> struct Parser {
  typedef string::const_iterator State;
  T solve(const string &S) {
    State begin = S.begin();
    return equation(begin);
  }
  
  T equation(State &begin) {
    T left = formula(begin);
    begin++;
    T right = formula(begin);
    return left == right;
  }
  
  T formula(State &begin) {
    switch(*begin) {
      case '(':
        begin++;
        T left = formula(begin);
        char op = *begin;
        begin++;
        if (op == '-')
          begin++;
        T right = formula(begin);
        begin++;
        return deduce(left, op, right);
      case '-':
        begin++;
        return !formula(begin);
      default:
        return boolean(begin);
    }
  }
  
  T deduce(T x, char op, T y) {
    switch(op) {
      case '*':
        return x and y;
      case '+':
        return x or y;
      default:
        return !x or y;
    }
  }
  
  T boolean(State &begin) {
    T ret;
    switch(*begin) {
      case 'T':
        ret = 1;
        break;
      case 'F':
        ret = 0;
        break;
      default:
        ret = (mask >> (*begin - 'a')) & 1;
    }
    begin++;
    return ret;
  }
};

void solve(string S) {
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
    solve(S);
  }
  return 0;
}