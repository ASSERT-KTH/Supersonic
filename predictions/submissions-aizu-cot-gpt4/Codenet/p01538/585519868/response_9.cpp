#include <stdio.h>
using namespace std;
int main() {
  int Q, N, count, tmp, max, S;
  bool FLG;
  scanf("%d", &Q);
  for (int loop = 0; loop < Q; loop++) {
    scanf("%d", &N);
    bool *table = new bool[N + 1]();
    count = 0;
    table[N] = true;
    FLG = false;
    while (true) {
      if (N / 10 == 0)
        break;
      max = 0;
      int NS = N, mod = N % 10;
      for (S = 10; S <= NS / 10; S *= 10) {
        NS /= 10;
        tmp = NS * mod;
        max = (max >= tmp) ? max : tmp;
        mod = N % S;
      }
      N = max;
      if (table[N] == true) {
        FLG = true;
        break;
      } else {
        table[N] = true;
        count++;
      }
    }
    delete[] table;
    if (FLG) {
      printf("-1\n");
    } else {
      printf("%d\n", count);
    }
  }
  return 0;
}