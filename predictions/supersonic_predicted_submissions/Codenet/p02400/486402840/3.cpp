#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int r, s, l, x;
  cin >> r;
  x = 3.141592653589;
  s = r * r * x;
  l = x * (r + r);
  printf("%.8lf %.8lf\n", s, l);
}
