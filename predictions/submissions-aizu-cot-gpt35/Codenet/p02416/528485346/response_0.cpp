#include <cstdio>
#include <cstring>

int main() {
  char num[1001];
  while (1) {
    fgets(num, sizeof(num), stdin);
    if (num[0] == '0')
      break;
    int sum = 0;
    int len = strlen(num);
    for (int i = 0; i < len; i++) {
      int digit = num[i] - '0';
      sum += digit;
    }
    printf("%d\n", sum);
  }
  return 0;
}