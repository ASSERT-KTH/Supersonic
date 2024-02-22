#include <algorithm>
#include <cstdio>
#include <cstring>

int main() {
  char* x = new char[1000005];
  std::fill(x, x + 1000005, 'A');
  scanf("%s", x);
  int leng = strlen(x);
  int a = 0, b = 0, c = 0, d = 0, maxi = 0;
  while (a < leng) {
    if (x[a] != 'J') {
      a++;
    } else {
      b = 0;
      c = 0;
      d = 0;
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
        maxi = std::max(maxi, c);
      }
    }
  }
  printf("%d\n", maxi);
  scanf("%d", &a);
  delete[] x;
  return 0;
}