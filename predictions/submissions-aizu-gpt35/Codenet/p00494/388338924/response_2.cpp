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
    if (x[a] != 'J') {
      continue;
    }
    b = 1;
    int c_count = 0;
    for (int c = a+1; c < leng && x[c] == 'O'; c++) {
      c_count++;
    }
    if (c_count == 0) {
      continue;
    }
    int i_count = 0;
    for (int d = a+1+c_count; d < leng && x[d] == 'I'; d++) {
      i_count++;
    }
    if (i_count == 0) {
      continue;
    }
    maxi = max(maxi, min(b, min(c_count, i_count)));
  }
  printf("%d\n", maxi);
  scanf("%d", &a);
  return 0;
}