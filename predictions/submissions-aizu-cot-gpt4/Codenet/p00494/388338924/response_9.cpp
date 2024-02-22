#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
char x[1000005];
int a = 0, b = 0, c = 0, d = 0, e, f, i, j, k, maxi = 0;
int main() {
  scanf("%s", x);
  int leng = strlen(x);
  for (a = 0; a < leng; a++) {
    if (x[a] == 'J') {
      for (; x[a] == 'J' && a < leng; b++, a++);
      for (; x[a] == 'O' && a < leng; c++, a++);
      for (; x[a] == 'I' && a < leng; d++, a++);
      if (b >= c && c <= d) {
        maxi = max(maxi, c);
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