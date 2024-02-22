#include <iostream>
using namespace std;
int main() {
  int is;
  int h, m, s;
  cin >> is;
  h = is / 3600;
  s = is % 3600; // Use modulus to get the remaining seconds
  m = s / 60;
  s = s % 60; // Use modulus to get the remaining seconds
  cout << h << ":" << m << ":" << s << endl;
  return 0;
}