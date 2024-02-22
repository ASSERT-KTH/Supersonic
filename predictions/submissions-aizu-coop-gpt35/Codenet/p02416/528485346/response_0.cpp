#include <cstdio>

int main() {
  char num[11];
  while (1) {
    scanf("%s", num);
    if (num[0] == '0')
      break;
    int sum = 0;
    int length = 0;
    while (num[length] != '\0') {
      sum += num[length] - '0';
      length++;
    }
    printf("%d\n", sum);
  }
  return 0;
}