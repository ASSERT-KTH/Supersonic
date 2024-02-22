#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int main() {
  char x[1000005];
  scanf("%s", x);
  int a = 0, b = 0, c = 0, d = 0, maxi = 0;
  int leng = strlen(x);
  while (a < leng) {
    char ch = x[a];
    switch (ch) {
      case 'J':
        while(x[a] == 'J') {
          b++;
          a++;
        }
        while(x[a] == 'O') {
          c++;
          a++;
        }
        while(x[a] == 'I') {
          d++;
          a++;
        }
        if (b >= c && c <= d) {
          maxi = max(maxi, c);
        }
        b = 0;
        c = 0;
        d = 0;
        break;
      default:
        a++;
        break;
    }
  }
  printf("%d\n", maxi);
  return 0;
}