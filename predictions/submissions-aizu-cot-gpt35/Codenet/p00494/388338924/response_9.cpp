#include <cstdio>
#include <cstring>

char x[1000005];
int b = 0, c = 0, d = 0, maxi = 0;

int main() {
  scanf("%s", x);
  char* ptr = x;
  
  while (*ptr != '\0') {
    if (*ptr == 'J') {
      while (*ptr == 'J') {
        b++;
        ptr++;
      }
      while (*ptr == 'O') {
        c++;
        ptr++;
      }
      while (*ptr == 'I') {
        d++;
        ptr++;
      }
      
      if (b >= c && c <= d) {
        maxi = (c > maxi) ? c : maxi;
      }
      
      b = 0;
      c = 0;
      d = 0;
    } else {
      ptr++;
    }
  }
  
  printf("%d\n", maxi);
  scanf("%d", &b);
  
  return 0;
}