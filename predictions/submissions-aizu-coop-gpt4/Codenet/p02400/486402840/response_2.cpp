#include <iostream>
#include <cmath>
using namespace std;

int main() {
  double r, s, l;
  cin >> r;

  s = r * r * M_PI;
  l = 2 * r * M_PI;

  cout.precision(9);
  cout << fixed << s << " " << l << "\n";

  return 0;
}