#include <iostream>
using namespace std;

int main() {
  int x, y;
  char z;
  while (1) {
    cin >> x >> z >> y;
    if (z == '?') {
      return 0;
    } else if (z == '+') {
      cout << x + y << endl;
    } else if (z == '-') {
      cout << x - y << endl;
    } else if (z == '/') {
      cout << x / y << endl;
    } else if (z == '*') {
      cout << x * y << endl;
    }
  }
  return 0;
}