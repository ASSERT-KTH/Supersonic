#include <iostream>
using namespace std;
int main() {
  int a, b, c = 1, i;
  cin >> a >> b;
  while (c > 0) {
    c = a % b;
    a = b;
    b = c;
  }
  cout << a << endl;
  return 0;
}