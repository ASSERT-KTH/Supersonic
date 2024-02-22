#include <iostream>
using namespace std;

// PI is a constant, define it as such for clarity and potential compiler optimization
const double PI = 3.141592653589;

int main() {
  double r, s, l;
  cin >> r;

  s = r * r * PI;
  l = 2 * PI * r;

  // Use 'cout' instead of 'printf' for output. It is type-safe and generally faster.
  cout.precision(8);
  cout << fixed << s << " " << l << endl;
  
  return 0;
}