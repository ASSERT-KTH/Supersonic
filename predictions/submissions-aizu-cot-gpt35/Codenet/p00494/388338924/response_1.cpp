#include <cstdio>
#include <cstring>

const int MAX_LENGTH = 1000005;

int main() {
  char x[MAX_LENGTH];
  scanf("%s", x);
  int leng = strlen(x);
  
  int a = 0, b = 0, c = 0, d = 0, maxi = 0;
  
  for (int i = 0; i < leng; i++) {
    if (x[i] == 'J') {
      b++;
      while (i + 1 < leng && x[i + 1] == 'J') {
        b++;
        i++;
      }
      while (i + 1 < leng && x[i + 1] == 'O') {
        c++;
        i++;
      }
      while (i + 1 < leng && x[i + 1] == 'I') {
        d++;
        i++;
      }
      if (b >= c && c <= d) {
        maxi = (c > maxi) ? c : maxi;
      }
      b = 0;
      c = 0;
      d = 0;
    }
  }
  
  printf("%d\n", maxi);
  
  int temp;
  scanf("%d", &temp);
  return 0;
}