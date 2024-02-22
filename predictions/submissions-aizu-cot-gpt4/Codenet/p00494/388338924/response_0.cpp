#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
char x[1000005];
int a = 0, b, c, d, maxi = 0;
int main() {
  scanf("%s", x);
  int leng = strlen(x);
  for (a = 0; a < leng; ++a) {
    if (x[a] == 'J') {
      for (b = 0; a < leng && x[a] == 'J'; ++a, ++b);
      for (c = 0; a < leng && x[a] == 'O'; ++a, ++c);
      for (d = 0; a < leng && x[a] == 'I'; ++a, ++d);
      maxi = max(maxi, min({b, c, d}));
    }
  }
  printf("%d\n", maxi);
  return 0;
}