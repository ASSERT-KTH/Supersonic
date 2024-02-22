#include <stdio.h>

int main() {
  int a[4];
  char buffer[110001] = {0};  // buffer to store the output
  for (int i = 0; i < 110000; ++i) buffer[i] = '(';  // fill the buffer with '('

  while (scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]) == 4 && a[0] != 0) {
    printf("%s", buffer);  // print the buffer
    printf("%d+%d+%d+%d", a[0], a[1], a[2], a[3]);
    puts("");  // print a newline character
  }
}