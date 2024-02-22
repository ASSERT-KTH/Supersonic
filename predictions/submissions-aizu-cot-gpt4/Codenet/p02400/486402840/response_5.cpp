#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
int main() {
  double r, s, l;
  cin >> r;
  s = r * r * M_PI;
  l = 2 * r * M_PI;
  printf("%.8lf %.8lf\n", s, l);
}