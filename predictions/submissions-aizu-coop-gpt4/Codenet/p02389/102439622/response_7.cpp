#include <stdio.h>
int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  int a_times_b = a * b;
  int a_times_2 = a * 2;
  int b_times_2 = b * 2;
  printf("%d %d\n", a_times_b, a_times_2 + b_times_2);
}