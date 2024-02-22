#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  const char NUL = '\0';
  char train[52];
  int t = 25, s = 25;
  
  int n;
  scanf("%d\n", &n);
  
  for (int i = 0; i < n; ++i) {
    memset(train, NUL, sizeof(train));
    
    int c = getchar();
    train[t] = c;
    
    int a, b;
    while ((a = getchar()) != '\n' && a != EOF) {
      b = getchar();
      c = getchar();
      
      if (a == '<' && b == '-') {
        train[--t] = c;
        if (t < s)
          s = t;
      } else if (a == '-' && b == '>')
        train[++t] = c;
    }
    
    puts(&train[s]);
  }
  
  return 0;
}