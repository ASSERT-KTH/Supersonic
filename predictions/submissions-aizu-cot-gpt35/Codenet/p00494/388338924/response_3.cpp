#include <cstdio>
#include <cstring>

char x[1000005];
int a = 0, b = 0, c = 0, d = 0, maxi = 0;

int main() {
  scanf("%s", x);
  int leng = strlen(x);

  while (a < leng) {
    if (x[a] == 'J') {
      b++;
      a++;
    } else if (x[a] == 'O') {
      c++;
      a++;
    } else if (x[a] == 'I') {
      d++;
      a++;
    } else {
      a++;
    }

    if (b >= c && c <= d) {
      maxi = c;
    }
  }

  printf("%d\n", maxi);
  scanf("%d", &a);
  return 0;
}