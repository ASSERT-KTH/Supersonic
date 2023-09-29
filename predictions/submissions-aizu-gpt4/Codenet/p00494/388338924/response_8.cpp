#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
char x[1000005];
int main() {
  fill(x, x + 1000005, 'A');
  scanf("%s", x);
  int a = 0, b = 0, c = 0, d = 0, maxi = 0, leng = strlen(x);
  while (a < leng) {
    if (x[a] == 'J') {
      b = 0; c = 0; d = 0;
      while (x[a] == 'J' && a < leng) { b++; a++; }
      while (x[a] == 'O' && a < leng) { c++; a++; }
      while (x[a] == 'I' && a < leng) { d++; a++; }
      if (b >= c && c <= d) maxi = max(maxi, c);
    } else a++;
  }
  printf("%d\n", maxi);
  return 0;
}