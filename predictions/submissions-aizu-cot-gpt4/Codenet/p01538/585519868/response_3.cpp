#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <stdio.h>
#include <vector>
using namespace std;
int main() {
  int Q, N, count, tmp, max, S;
  bool FLG;
  scanf("%d", &Q);
  std::vector<bool> table(1000001, false);
  for (int loop = 0; loop < Q; loop++) {
    count = 0;
    scanf("%d", &N);
    FLG = false;
    while (true) {
      if (N / 10 == 0)
        break;
      max = 0;
      for (S = 10; N / S != 0; S *= 10) {
        tmp = (N / S) * (N % S);
        max = std::max(max, tmp);
      }
      N = max;
      if (table[N]) {
        FLG = true;
        break;
      }
      table[N] = true;
      count++;
    }
    table[N] = true;
    if (FLG) {
      printf("-1\n");
    } else {
      printf("%d\n", count);
    }
  }
  return 0;
}