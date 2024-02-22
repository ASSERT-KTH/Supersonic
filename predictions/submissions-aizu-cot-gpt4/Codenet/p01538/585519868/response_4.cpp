#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <stdio.h>
#include <vector>

int main() {
  int Q, N, count, tmp, max, S;
  bool FLG;
  scanf("%d", &Q);
  std::vector<bool> table(1000001);
  
  for (N = 1; N <= 1000000; N++) {
    table[N] = false;
    int cur = N;
    while (cur >= 10) {
      max = 0;
      for (S = 10; cur / S != 0; S *= 10) {
        tmp = (cur / S) * (cur % S);
        max = (max >= tmp) ? max : tmp;
      }
      cur = max;
      if (table[cur] == true) {
        table[N] = true;
        break;
      }
    }
  }
  
  for (int loop = 0; loop < Q; loop++) {
    scanf("%d", &N);
    FLG = table[N];
    if (FLG) {
      printf("-1\n");
    } else {
      printf("%d\n", N);
    }
  }
  return 0;
}