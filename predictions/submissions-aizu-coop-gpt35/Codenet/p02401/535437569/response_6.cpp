#include <cstdio>

enum Operator { ADD, SUBTRACT, MULTIPLY, DIVIDE };

int main() {
  int x, y;
  Operator op;

  while (true) {
    if (scanf("%d %c %d", &x, reinterpret_cast<char*>(&op), &y) != 3) {
      return 0;  // Invalid input or end of input
    }

    switch (op) {
      case ADD:
        printf("%d\n", x + y);
        break;
      case SUBTRACT:
        printf("%d\n", x - y);
        break;
      case MULTIPLY:
        printf("%d\n", x * y);
        break;
      case DIVIDE:
        if (y != 0) {
          printf("%d\n", x / y);
        } else {
          printf("Division by zero error\n");
        }
        break;
      default:
        printf("Invalid operator\n");
        break;
    }
  }

  return 0;
}