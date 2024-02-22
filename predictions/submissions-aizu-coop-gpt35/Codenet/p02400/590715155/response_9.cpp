#include <cstdio>
using namespace std;

int main() {
  const double PI = 3.14; // Reduced precision for PI
  double r;
  
  scanf("%lf", &r); // Using scanf for input
  
  printf("%.2lf %.2lf\n", PI * r * r, 2 * PI * r); // Using printf for output
  
  return 0;
}