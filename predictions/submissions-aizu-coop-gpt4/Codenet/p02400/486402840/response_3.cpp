#include <cstdio>   // for printf(), scanf()
#include <cmath>    // for M_PI
using namespace std;
int main() {
  double r, s, l;
  scanf("%lf", &r); // faster than cin
  s = r * r * M_PI; // use M_PI from cmath instead of defining our own x
  l = M_PI * (r + r); 
  printf("%.8lf %.8lf\n", s, l);
}