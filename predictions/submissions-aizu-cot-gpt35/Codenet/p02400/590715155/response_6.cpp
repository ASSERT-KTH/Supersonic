#include <cstdio>

int main() {
  float PI = 3.141592653589f;
  float r;
  scanf("%f", &r);
  printf("%f %f\n", PI * r * r, 2 * PI * r);
  return 0;
}