#include <iostream>
using namespace std;
int main() {
  int is;
  int h, m, s;
  cin >> is;
  h = is / 3600;
  is %= 3600; // Use modulus operation to directly compute the remainder
  m = is / 60;
  is %= 60; // Use modulus operation to directly compute the remainder
  cout << h << ":" << m << ":" << is << endl;
  return 0;
}