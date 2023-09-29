#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  double r, s, l;
  cin >> r;
  const double pi = 3.141592653589;
  s = r * r * pi;
  l = 2 * r * pi;
  printf("%.8lf %.8lf\n", s, l);
}