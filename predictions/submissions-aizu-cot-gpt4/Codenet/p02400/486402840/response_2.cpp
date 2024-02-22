#include <iostream>
#include <cmath>
using namespace std;
int main() {
  float r, s, l;
  cin >> r;
  s = r * r * M_PI;
  l = M_PI * 2 * r;
  cout.precision(8);
  cout << s << " " << l << "\n";
}