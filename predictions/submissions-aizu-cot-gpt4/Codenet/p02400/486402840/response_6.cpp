#include <iostream>
using namespace std;

int main() {
  const double Pi = 3.141592653589;
  double r = 0.0, s = 0.0, l = 0.0;
  cin >> r;
  s = Pi * r * r;
  l = 2.0 * Pi * r;
  cout.precision(8);
  cout << fixed << s << " " << l << endl;
  return 0;
}