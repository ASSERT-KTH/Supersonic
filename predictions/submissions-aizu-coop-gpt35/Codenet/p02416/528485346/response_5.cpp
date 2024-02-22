#include <cstdio>

int main() {
  int num;
  while (true) {
    scanf("%d", &num);
    if (num == 0)
      break;
    int sum = 0;
    while (num > 0) {
      sum += num % 10;
      num /= 10;
    }
    printf("%d\n", sum);
  }
  return 0;
}