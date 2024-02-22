#include <cstdio>
#include <iostream>
using namespace std;

const double PI = 3.141592653589; // PI is more descriptive than x and defined as constant

int main() {
  double r, s, l;
  cin >> r;
  
  s = r * r * PI; // calculate area
  l = 2 * r * PI; // calculate circumference
  
  printf("%.8lf %.8lf\n", s, l);
}