#include <cstdio>
#include <cstring>
using namespace std;

int main() {
  char x[1000005];
  scanf("%s", x);

  int leng = strlen(x);
  int a = 0, maxi = 0;

  while (a < leng) {
    if (x[a] != 'J') {
      a++;
    } else {
      int b = 0, c = 0, d = 0;

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
        maxi = c > maxi ? c : maxi;
      }
    }
  }

  printf("%d\n", maxi);
  scanf("%*d"); // Read and ignore an integer
  return 0;
}