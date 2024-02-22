#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
  int x, y, s;
  while (scanf("%d %d %d", &x, &y, &s) && (x || y || s)) {
    int maxi = 0, a = 1, b, taxA, taxB;
    while (a < s) {
      b = (s*100 - a*x) / (100 + x);
      if ((a * x + b * x)/100 == s && b != 0) {
        taxA = (a * y) / 100;
        taxB = (b * y) / 100;
        maxi = max(maxi, taxA + taxB);
      }
      a++;
    }
    printf("%d\n", maxi);
  }
  return 0;
}