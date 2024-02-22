#include <stdio.h>

#define MAX_SIZE 999

int main() {
  int b, d = 0;
  int c[MAX_SIZE] = {0};

  scanf("%d", &b);

  for (int i = 0; i < b; i++) {
    int num;
    scanf("%d", &num);
    c[num]++;
  }

  for (int i = 0; i < b; i++) {
    int num;
    scanf("%d", &num);
    d += c[num];
  }

  printf("%d\n", d);

  return 0;
}