#include <cstdio>

int main() {
  int a = 0, b = 0, c = 0, maxi = 0;
  char ch;
  
  while (scanf("%c", &ch) != EOF) {
    if (ch == 'J') {
      b++;
      while (scanf("%c", &ch) != EOF && ch == 'O') {
        c++;
        while (scanf("%c", &ch) != EOF && ch == 'I') {
          a++;
          if (b >= c && c <= a) {
            maxi = (c > maxi) ? c : maxi;
          }
        }
        a = 0;
      }
      c = 0;
    }
  }
  
  printf("%d\n", maxi);
  scanf("%d", &a);
  return 0;
}