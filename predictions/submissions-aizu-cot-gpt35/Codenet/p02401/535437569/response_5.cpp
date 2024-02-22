#include <iostream>
using namespace std;

int main() {
  int x, y;
  char z;
  while (true) {
    cin >> x >> z >> y;
    if (z == '?') {
      break;
    }
    switch (z) {
      case '+':
        cout << x + y << endl;
        break;
      case '-':
        cout << x - y << endl;
        break;
      case '/':
        cout << x / y << endl;
        break;
      case '*':
        cout << x * y << endl;
        break;
    }
  }
  return 0;
}