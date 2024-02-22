#include <cstdio>
#include <cstring>

int main() {
  char num[1001];
  while (true) {
    fgets(num, sizeof(num), stdin);
    if (num[0] == '0')
      break;
    int sum = 0;
    int len = strlen(num) - 1; // Subtract 1 to exclude newline character
    for (int i = 0; i < len; i++) {
      sum += num[i] - '0';
    }
    printf("%d\n", sum);
  }
  return 0;
}