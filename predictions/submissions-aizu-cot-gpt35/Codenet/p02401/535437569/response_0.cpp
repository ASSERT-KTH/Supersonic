#include <iostream>
using namespace std;

int main() {
  int x, y;
  char z;
  
  while (true) {
    cin >> x >> z >> y;
    
    switch (z) {
      case '?':
        return 0;
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