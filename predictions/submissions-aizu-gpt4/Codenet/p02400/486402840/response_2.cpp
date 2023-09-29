#include <cstdio>
#include <cmath>
using namespace std;
int main() {
  double r;
  cin >> r;
  printf("%.8lf %.8lf\n", M_PI * r * r, 2 * M_PI * r);
}