#include <cmath>
#include <complex>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  double x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  double distance = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
  printf("%.5f\n", distance);
  return 0;
}