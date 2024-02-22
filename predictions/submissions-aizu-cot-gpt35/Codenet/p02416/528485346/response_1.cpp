#include <cstdio>
#include <cstring>

int main() {
  char num[1001];

  while (1) {
    scanf("%s", num);
    if (num[0] == '0')
      break;

    int len = strlen(num);
    int sum = 0;
    char* ptr = num;

    for (int i = 0; i < len; i++) {
      sum += *ptr - '0';
      ptr++;
    }

    printf("%d\n", sum);
  }

  return 0;
}