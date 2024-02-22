#include <iostream>
using namespace std;

int main() {
  int x, y, result;
  char z;

  while (true) {
    cin >> x >> z >> y;

    switch(z) {
      case '?':
        return 0;
      case '+':
        result = x + y;
        break;
      case '-':
        result = x - y;
        break;
      case '/':
        if (y != 0) {
          result = x / y;
        } else {
          cout << "Error: Division by zero is not allowed." << endl;
          continue;
        }
        break;
      case '*':
        result = x * y;
        break;
      default:
        cout << "Invalid operator." << endl;
        continue;
    }

    cout << result << endl;
  }
}