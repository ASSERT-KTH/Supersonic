#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  double r, s, l, x;
  cin >> r;
  x = 3.141592653589;
  s = r * r * x;
  l = x * (r + r);
  printf("%.9lf %.9lf\n", s, l);
}