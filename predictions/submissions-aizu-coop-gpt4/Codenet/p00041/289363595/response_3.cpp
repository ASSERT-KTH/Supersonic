#include <stdio.h>

int main() {
  int a[4];
  char parentheses[110001]; // array to hold parentheses
  memset(parentheses, '(', 110000); // fill the array with '('
  parentheses[110000] = '\0'; // null-terminate the string

  while (1) {
    for (int i = 0; i < 4; ++i) {
      scanf("%d", &a[i]);
    }
    if (a[0] == 0) {
      break;
    }
    printf("%s", parentheses); // print all parentheses at once
    printf("%d+%d+%d+%d\n", a[0], a[1], a[2], a[3]);
  }
}