#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
char x[1000005];
int counts[3] = {0, 0, 0};  // counts for J, O, I respectively
int a = 0, b = 0, c = 0, d = 0, e, f, i, j, k, maxi = 0, leng = 0;
int main() {
  // read the string and find its length
  while(scanf("%c", &x[leng]), x[leng] != '\n'){
    ++leng;
  }
  x[leng] = '\0';
  while (a < leng) {
    if (x[a] != 'J') {
      a++;
    } else {
      for (int i = 0; i < 3; ++i) {
        while (x[a] == "JOI"[i]) {
          ++counts[i];
          ++a;
        }
      }
      if (counts[0] >= counts[1] && counts[1] <= counts[2]) {
        maxi = max(maxi, counts[1]);
      }
      for (int i = 0; i < 3; ++i) {
        counts[i] = 0;
      }
    }
  }
  printf("%d\n", maxi);
  scanf("%d", &a);
  return 0;
}