#include <cstdio>
#include <cstring>
using namespace std;
char x[1000005];
int a = 0, b = 0, c = 0, d = 0, e, f, i, j, k, maxi = 0;
int main() {
  scanf("%s", x);
  int leng = strlen(x);
  for(int i=0;i<leng;i++) {
    if (x[i] == 'J') {
      b++;
    } else if (x[i] == 'O') {
      c++;
    } else if (x[i] == 'I') {
      d++;
    }
    while (b > d || c > d) {
      if (x[a] == 'J') {
        b--;
      } else if (x[a] == 'O') {
        c--;
      } else if (x[a] == 'I') {
        d--;
      }
      a++;
    }
    if (b >= c && c <= d) {
      maxi = max(maxi, c);
    }
  }
  printf("%d\n", maxi);
  return 0;
}