#include <iostream>
using namespace std;
int main() {
  int is;
  int h, m, s;
  cin >> is;
  h = is / 3600;
  // Use modulo operation to get the remaining seconds after dividing into hours
  is = is % 3600;
  m = is / 60;
  // Use modulo operation to get the remaining seconds after dividing into minutes
  s = is % 60;
  cout << h << ":" << m << ":" << s << endl;
  return 0;
}