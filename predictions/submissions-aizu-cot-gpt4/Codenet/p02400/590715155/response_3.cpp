#include <iostream>
using namespace std;
int main() {
  constexpr double PI = 3.141592653589;
  double r;
  cin >> r;
  cout << PI * r * r << " " << 2 * PI * r << "\n";
  return 0;
}