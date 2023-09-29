#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  double r, s, l;
  const double pi = 3.141592653589;
  cin >> r;
  s = r * r * pi;
  l = 2 * pi * r;
  printf("%.8lf %.8lf\n", s, l);
}