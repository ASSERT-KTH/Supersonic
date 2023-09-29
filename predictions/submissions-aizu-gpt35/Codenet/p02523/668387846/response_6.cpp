#include <cmath>
#include <iostream>
using namespace std;
int main() {
  double x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  double dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
  printf("%.5f\n", dist);
  return 0;
}