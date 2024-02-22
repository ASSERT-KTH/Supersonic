#include <cstdio>

int main() {
  int x, y;
  char z;
  while (1) {
    char line[100];
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d %c %d", &x, &z, &y);
    if (z == '?') {
      return 0;
    } else {
      int result;
      switch (z) {
        case '+':
          result = x + y;
          break;
        case '-':
          result = x - y;
          break;
        case '*':
          result = x * y;
          break;
        case '/':
          result = x * (1.0 / y);
          break;
      }
      char output[100];
      sprintf(output, "%d\n", result);
      puts(output);
    }
  }
  return 0;
}