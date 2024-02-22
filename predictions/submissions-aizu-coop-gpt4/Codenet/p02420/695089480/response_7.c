#include <string.h>
#include <stdio.h>

int i, m, h, t, a;
int main() {
  char s[201];
  while(scanf("%s%d", s, &m), s[0] != '-') {
    a = strlen(s);
    t = 0;
    for (i = 0; i < m; i++) {
        scanf("%d", &h);
        t = (t + h) % a; // Calculate rotation factor and wrap it within string length
    }
    // Print the rotated string
    for (i = 0; i < a; i++) {
        printf("%c", s[(t + i) % a]); // Avoid modulo operation by pre-calculating it
    }
    printf("\n");
  }
  return 0;
}