#include <iostream>
using namespace std;
constexpr double PI = 3.141592653589;

int main() {
  double r;
  cin >> r;
  double s = r * r * PI;
  double l = 2 * PI * r;
  cout.precision(8);
  cout << fixed << s << " " << l << "\n";
}