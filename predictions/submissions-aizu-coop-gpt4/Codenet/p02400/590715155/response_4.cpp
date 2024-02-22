#include <iostream>
using namespace std;
int main() {
  constexpr double PI = 3.141592653589;
  double r;
  cin >> r;
  double pi_r = PI * r; // calculate PI * r once
  cout << pi_r * r << " " << 2 * pi_r << "\n"; // use cout instead of printf
  return 0;
}