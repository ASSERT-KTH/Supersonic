#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
char x[1000005];
int a = 0, b = 0, c = 0, d = 0, maxi = 0;
int main() {
  int leng = scanf("%s", x);
  for (a = 0; a < leng;) {
    if (x[a] != 'J') {
      a++;
    } else {
      for (; x[a] == 'J'; a++, b++);
      for (; x[a] == 'O'; a++, c++);
      for (; x[a] == 'I'; a++, d++);
      if (b >= c && c <= d) {
        maxi = max(maxi, c);
      }
      b = c = d = 0;
    }
  }
  printf("%d\n", maxi);
  return 0;
}