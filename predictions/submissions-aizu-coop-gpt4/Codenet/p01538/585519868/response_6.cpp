#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <stdio.h>
#include <vector>
using namespace std;
int main() {
  int Q, N, count, tmp, max, S;
  bool FLG, prev;
  scanf("%d", &Q);
  bool *table = new bool[1000001];
  for (int loop = 0; loop < Q; loop++) {
    count = 0;
    scanf("%d", &N);
    prev = table[N];
    table[N] = true;
    FLG = false;
    while (true) {
      if (N / 10 == 0)
        break;
      max = 0;
      for (S = 10; N / S != 0; S *= 10) {
        tmp = (N / S) * (N % S);
        max = (max >= tmp) ? max : tmp;
      }
      N = max;
      if (prev) {
        FLG = true;
        break;
      } else {
        prev = table[N];
        table[N] = true;
        count++;
      }
    }
    if (FLG) {
      printf("-1\n");
    } else {
      printf("%d\n", count);
    }
  }
  delete [] table; // deallocate memory
  return 0;
}