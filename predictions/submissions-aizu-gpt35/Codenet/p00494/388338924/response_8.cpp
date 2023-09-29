#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
char x[1000005];
int a = 0, b = 0, c = 0, d = 0, e, f, i, j, k, maxi = 0;
int main() {
  fill(x, x + 1000005, 'A');
  scanf("%s", x);
  int leng = strlen(x);
  for (int a = 0; a < leng; a++) {
    if (x[a] == 'J') {
      b++;
    } else if (x[a] == 'O') {
      c = min(b, c + 1);
      b = 0;
    } else if (x[a] == 'I') {
      d = min(c, d + 1);
      c = 0;
    }
    maxi = max(maxi, d);
  }
  printf("%d\n", maxi);
  scanf("%d", &a);
  return 0;
}