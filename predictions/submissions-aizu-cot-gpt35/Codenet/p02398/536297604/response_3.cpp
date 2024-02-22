#include <iostream>
using namespace std;

int main() {
  int a, b, c, t = 0;
  cin >> a >> b >> c;
  
  if (c == 0) {
    cout << "Cannot divide by zero" << endl;
    return 0;
  }
  
  if (a > b) {
    cout << "Invalid range" << endl;
    return 0;
  }
  
  for (int i = a; i <= b; i++) {
    if (i != 0 && c % i == 0) {
      t++;
    }
  }
  
  cout << t << endl;
  return 0;
}