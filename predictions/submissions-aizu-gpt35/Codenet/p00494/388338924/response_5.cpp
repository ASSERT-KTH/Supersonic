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
  for (int a = 0; a < leng;) {
    if (x[a] != 'J') {
      a++;
      continue;
    }
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
      maxi = max(maxi, c);
    }
    b = 0;
    c = 0;
    d = 0;
  }
  printf("%d\n", maxi);
  scanf("%d", &a);
  return 0;
}