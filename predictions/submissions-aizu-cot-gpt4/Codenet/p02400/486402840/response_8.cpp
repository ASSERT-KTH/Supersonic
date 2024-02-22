#include <iostream>
using namespace std;
int main() {
  double r, s, l;
  double x = 3.141592653589;
  cin >> r;
  s = r * r * x;
  l = 2 * x * r;
  cout.precision(8);
  cout << s << " " << l << "\n";
}