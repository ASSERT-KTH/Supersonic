#include <iostream>
using namespace std;
int main() {
  const double PI = 3.141592653589;
  double r;
  cin >> r;
  double pi_r = PI * r;
  cout << pi_r * r << " " << 2 * pi_r << "\n";
  return 0;
}