#include <iostream>
using namespace std;
int main() {
  int h, m, s;
  cin >> s;
  h = s / 3600;
  s %= 3600; // Use modulus operator to get the remaining seconds
  m = s / 60;
  s %= 60; // Use modulus operator to get the remaining seconds
  cout << h << ":" << m << ":" << s << endl;
  return 0;
}