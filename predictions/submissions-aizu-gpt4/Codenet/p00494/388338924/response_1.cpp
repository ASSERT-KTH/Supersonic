#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
char x[1000005];
int a = 0, b = 0, c = 0, d = 0, maxi = 0;
int main() {
  fill(x, x + 1000005, 'A');
  scanf("%s", x);
  int leng = strlen(x);
  for(a = 0; a < leng; a++) {
    if (x[a] == 'J') {
      for (; x[a] == 'J' && a < leng; b++, a++);
      for (; x[a] == 'O' && a < leng; c++, a++);
      for (; x[a] == 'I' && a < leng; d++, a++);
      if (b >= c && c <= d) {
        maxi = max(maxi, c);
      }
      b = c = d = 0;
    }
  }
  printf("%d\n", maxi);
  return 0;
}