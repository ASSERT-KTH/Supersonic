#include <iostream>
using namespace std;

constexpr double PI = 3.141592653589;

int main() {
  double r;
  cin >> r;
  double r_square = r * r;
  cout << PI * r_square << ' ' << 2 * PI * r << '\n';
  return 0;
}