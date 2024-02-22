#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);
  
  int x, y;
  char z;
  while (true) {
    cin >> x >> z >> y;
    switch(z) {
      case '+':
        cout << x + y << "\n";
        break;
      case '-':
        cout << x - y << "\n";
        break;
      case '/':
        if(y != 0)
          cout << x / y << "\n";
        else
          cout << "Cannot divide by zero\n";
        break;
      case '*':
        cout << x * y << "\n";
        break;
      case '?':
        return 0;
    }
  }
  return 0;
}