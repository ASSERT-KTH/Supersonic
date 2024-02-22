#include <cstdio>
#include <cstring>

int main() {
  char x[1000005];
  memset(x, 'A', sizeof(x));  // Optimization 1: Use memset instead of fill

  scanf("%s", x);
  int leng = strlen(x);
  
  int a = 0, b = 0, c = 0, d = 0;  // Optimization 4: Use local variables instead of global variables
  int maxi = 0;

  while (a < leng) {  // Optimization 3: Simplify loop conditions
    if (x[a] != 'J') {
      a++;
    } else {
      while (x[a] == 'J') {  // Optimization 3: Simplify loop conditions
        b++;
        a++;
      }
      while (x[a] == 'O') {  // Optimization 3: Simplify loop conditions
        c++;
        a++;
      }
      while (x[a] == 'I') {  // Optimization 3: Simplify loop conditions
        d++;
        a++;
      }
      if (b >= c && c <= d) {
        maxi = (c > maxi) ? c : maxi;  // Optimization 3: Use ternary operator for max calculation
      }
      b = 0;
      c = 0;
      d = 0;
    }
  }

  printf("%d\n", maxi);
  scanf("%d", &a);

  return 0;
}