#include <iostream>
using namespace std;

int main() {
  const double PI = 3.141592653589;
  double r, s, l;
  cin >> r;
  s = r * r * PI;
  l = 2 * PI * r;
  cout.precision(9);
  cout << s << " " << l << "\n";
}