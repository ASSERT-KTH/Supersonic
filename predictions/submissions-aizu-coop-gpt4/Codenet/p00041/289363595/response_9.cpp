#include <stdio.h>

int main() {
  int a[4];
  char brackets[110001];  // buffer to store 110000 opening brackets
  memset(brackets, '(', 110000);  // fill the buffer with opening brackets
  brackets[110000] = '\0';  // null terminate the string

  while (1) {
    if (fread(a, sizeof(int), 4, stdin) != 4) {  // read four integers at once
      perror("fread failed");
      return 1;
    }
    if (a[0] == 0) {
      break;
    }
    printf("%s%d+%d+%d+%d\n", brackets, a[0], a[1], a[2], a[3]);
  }
  return 0;
}