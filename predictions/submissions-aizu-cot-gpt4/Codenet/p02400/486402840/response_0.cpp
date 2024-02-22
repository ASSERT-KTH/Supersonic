#include <iostream>
using namespace std;

const double PI = 3.141592653589;

int main() {
  double r, s, l;
  cin >> r;
  s = r * r * PI;
  l = 2 * PI * r;
  cout.precision(8);
  cout << s << " " << l << "\n";
}