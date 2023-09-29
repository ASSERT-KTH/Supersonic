#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  double r, s, l, x;
  scanf("%lf", &r);
  x = 3.141592653589;
  s = r * r * x;
  l = x * r * 2;
  printf("%.8lf %.8lf\n", s, l);
}