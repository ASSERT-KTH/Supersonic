#include <cstdio>

char x[1000005];
int a = 0, b = 0, c = 0, d = 0, maxi = 0;

int main() {
  scanf("%s", x);
  while (x[a] != '\0') {
    if (x[a] == 'J') {
      while (x[a] == 'J') {
        b++;
        a++;
      }
      while (x[a] == 'O') {
        c++;
        a++;
      }
      while (x[a] == 'I') {
        d++;
        a++;
      }
      if (b >= c && c <= d) {
        if(c > maxi){
          maxi = c;
        }
      }
      b = c = d = 0;
    } else {
      a++;
    }
  }
  printf("%d\n", maxi);
  return 0;
}