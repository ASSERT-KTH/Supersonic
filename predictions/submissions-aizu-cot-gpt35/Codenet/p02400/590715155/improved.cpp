#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  double pi = 3.1415926535897;
  double r;
  cin >> r;
  printf("%lf %lf\n", pi * r * r, 2 * pi * r);
  return 0;
}
