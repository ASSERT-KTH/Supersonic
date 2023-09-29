#include <cstdio>
#include <cstring>

const int maxn = 1000005;

char x[maxn];

int main() {
  scanf("%s", x);
  int leng = strlen(x);
  int b = 0, c = 0, d = 0, maxi = 0;
  for (int a = 0; a < leng; ++a) {
    if (x[a] == 'J') {
      ++b;
    } else if (x[a] == 'O') {
      ++c;
    } else if (x[a] == 'I') {
      ++d;
    }
    if (b >= c && c <= d) {
      maxi = d > maxi ? d : maxi;
    }
  }
  printf("%d\n", maxi);
  return 0;
}
