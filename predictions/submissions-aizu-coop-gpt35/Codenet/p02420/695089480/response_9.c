#include <stdio.h>
#include <string.h>

int main() {
  char s[201];
  int m, h, a, i;
  while (scanf("%s%d", s, &m) == 2 && s[0] != '-') {
    a = strlen(s); // Calculate the length of the input string

    // Combine the nested loops and perform string manipulation in a single loop
    char result[201];
    int t = 0;
    for (i = 0; i < a; i++) {
      scanf("%d", &h);
      t += h;
      result[i] = s[(t + i) % a];
    }
    result[i] = '\0'; // Null-terminate the result string

    printf("%s\n", result); // Print the entire result string at once
  }
  return 0;
}