#include <cstdio>
#include <cstring>

int main() {
  int x, y;
  char input[100];
  
  while (1) {
    fgets(input, sizeof(input), stdin);
    
    if (input[0] == '?') {
      return 0;
    }
    
    sscanf(input, "%d %c %d", &x, &z, &y);
    
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
        result = x / y;
        break;
    }
    
    printf("%d\n", result);
  }
  
  return 0;
}