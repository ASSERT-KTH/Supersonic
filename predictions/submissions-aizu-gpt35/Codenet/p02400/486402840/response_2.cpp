#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  double r, s, l;
  const double x = 3.141592653589;
  cin >> r;
  s = r * r * x;
  l = x * r * 2;
  printf("%.8lf %.8lf\n", s, l);
  return 0;
}