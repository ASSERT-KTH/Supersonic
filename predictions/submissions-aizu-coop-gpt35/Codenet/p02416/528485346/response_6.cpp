#include <cstdio>

int main() {
  char num[1001];
  while (1) {
    scanf("%s", num);
    if (num[0] == '0')
      break;
      
    int len = 0;
    while (num[len] != '\0')
      len++;
      
    int sum = 0;
    for (int i = 0; i < len; i++) {
      sum += num[i] - '0';
    }
    printf("%d\n", sum);
  }
  return 0;
}