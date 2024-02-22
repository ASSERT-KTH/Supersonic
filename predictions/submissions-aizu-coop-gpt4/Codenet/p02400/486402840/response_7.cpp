#include <iostream>
#include <iomanip>

#define PI 3.141592653589

using namespace std;

int main() {
  double r, s, l;
  cin >> r;
  s = r * r * PI;
  l = 2 * PI * r;
  cout << fixed << setprecision(8) << s << " " << l << "\n";
  return 0;
}