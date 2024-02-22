#include <cstdio>
#include <cstring>
using namespace std;

char x[1000005];
int a = 0, b = 0, c = 0, d = 0, maxi = 0;

int main() {
  scanf("%s", x);
  int leng = strlen(x);

  for (a = 0; a < leng; ++a) {
    if (x[a] == 'J') {
      b++;
      if (b > 1) { // reset counts when a new 'JOI' sequence starts
        b = c = d = 1;
      }
    } else if (x[a] == 'O') {
      c++;
    } else if (x[a] == 'I') {
      d++;
    }
    // check the counts after each character is processed
    if (b >= c && c <= d) {
      maxi = max(maxi, c);
    }
  }

  printf("%d\n", maxi);
  scanf("%d", &a);
  return 0;
}