#include <cstdio>
#include <cstring>

int main() {
  char* x = new char[1000005];
  scanf("%s", x);
  int leng = strlen(x);
  int a = 0, b = 0, c = 0, d = 0, maxi = 0;
  while (a < leng) {
    if (x[a] != 'J') {
      a++;
    } else {
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
        maxi = (c > maxi) ? c : maxi;
      }
      b = 0;
      c = 0;
      d = 0;
    }
  }
  printf("%d\n", maxi);
  delete[] x;
  scanf("%d", &a);
  return 0;
}