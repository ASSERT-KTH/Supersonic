#include <iostream>
using namespace std;
int main() {
  double pai = 3.141592653589;
  int a, b;
  cin >> a >> b;
  if (a > b)
    cout << "a > b\n";
  else if (a < b)
    cout << "a < b\n";
  else
    cout << "a == b\n";
  return 0;
}