#include <iostream>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  // Compare a and b using ternary operator
  cout << (a > b ? "a > b" : (a < b ? "a < b" : "a == b")) << endl;

  return 0;
}