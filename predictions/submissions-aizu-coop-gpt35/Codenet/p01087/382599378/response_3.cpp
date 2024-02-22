#include <iostream>
#include <numeric>
using namespace std;

int solve(const string& expression, int& index) {
  if (isdigit(expression[index])) {
    return expression[index++] - '0';
  }
  char op = expression[index++];
  int result;
  if (op == '+') {
    result = 0;
    while (isdigit(expression[index])) {
      result += expression[index++] - '0';
    }
  } else {
    result = 1;
    while (isdigit(expression[index])) {
      result *= expression[index++] - '0';
    }
  }
  return result;
}

int main() {
  int n;
  while (cin >> n, n) {
    string expression;
    int result = 0;
    for (int i = 0; i < n; ++i) {
      cin >> expression;
      int index = 0;
      result += solve(expression, index);
    }
    cout << result << endl;
  }
  return 0;
}