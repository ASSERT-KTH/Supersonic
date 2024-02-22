#include <stdio.h>
#include <math.h>
int main() {
  int d, e;
  while (1) {
    scanf("%d %d", &d, &e);
    double min = 100000*100000; // square of the original min value
    if (d == 0 && e == 0)
      break;
    for (int i = 0; i <= d; i++) {
      int j = d - i;
      double costSq = i * i + j * j; // square of the cost
      double gapSq = (costSq - e * e); // square of the gap
      if (gapSq < min) {
        min = gapSq;
      }
    }
    printf("%.7f\n", sqrt(min)); // take sqrt only once, just before printing
  }
  return 0;
}