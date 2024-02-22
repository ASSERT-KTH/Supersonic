#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
char x[1000005];
int a = 0, b = 0, c = 0, d = 0, maxi = 0;
int main() {
  fgets(x, sizeof(x), stdin);
  int leng = strlen(x);
  while (a < leng) {
    switch (x[a]) {
      case 'J':
        while (x[a++] == 'J') b++;
        while (x[a++] == 'O') c++;
        while (x[a++] == 'I') d++;
        if (b >= c && c <= d) maxi = max(maxi, c);
        b = c = d = 0;
        break;
      default:
        a++;
    }
  }
  printf("%d\n", maxi);
  return 0;
}