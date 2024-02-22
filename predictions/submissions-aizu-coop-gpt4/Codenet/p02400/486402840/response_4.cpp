#include <iostream>
#include <cmath>
using namespace std;

int main() {
  const double PI = M_PI;
  double r, area, circumference;
  cin >> r;
  area = r * r * PI;
  circumference = 2 * PI * r;
  cout.precision(8);
  cout << fixed << area << " " << circumference << "\n";
  return 0;
}