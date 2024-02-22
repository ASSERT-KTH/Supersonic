#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

int mask;

template <class T>
struct Parser {
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
    stack<T> operands;
    stack<char> operators;

    while (true) {
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
        operands.push(ret);
      } else if (*begin == '-') {
        begin++;
        T result = !formula(begin);
        operands.push(result);
      } else {
        T result = boolean(begin);
        operands.push(result);
      }

      if (begin == '\0' || *begin == ')') {
        break;
      }

      char op = *begin;
      begin++;

      while (!operators.empty() && hasPrecedence(operators.top(), op)) {
        char topOp = operators.top();
        operators.pop();
        T right = operands.top();
        operands.pop();
        T left = operands.top();
        operands.pop();
        T result = deduce(left, topOp, right);
        operands.push(result);
      }

      operators.push(op);
    }

    while (!operators.empty()) {
      char op = operators.top();
      operators.pop();
      T right = operands.top();
      operands.pop();
      T left = operands.top();
      operands.pop();
      T result = deduce(left, op, right);
      operands.push(result);
    }

    return operands.top();
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

  bool hasPrecedence(char op1, char op2) {
    if (op2 == '(' || op2 == ')')
      return false;
    if ((op1 == '*' || op1 == '+') && (op2 == '-' || op2 == '*'))
      return false;
    return true;
  }
};

void solve(string S) {
  Parser<bool> ps;
  unordered_map<string, bool> memo;

  int numVars = count_if(S.begin(), S.end(), [](char c) { return isalpha(c); });
  int numCombinations = 1 << numVars;

  for (mask = 0; mask < numCombinations; mask++) {
    string key = to_string(mask) + S;
    if (memo.count(key) == 0) {
      bool result = ps.solve(S);
      memo[key] = result;
    }
    if (!memo[key]) {
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