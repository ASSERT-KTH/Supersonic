#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <stdio.h>
#include <vector>
using namespace std;
int main() {
  int Q, N, count, tmp, max;
  scanf("%d", &Q);
  vector<bool> table(1000001, false);
  for (int loop = 0; loop < Q; loop++) {
    fill(table.begin(), table.end(), false);
    count = 0;
    scanf("%d", &N);
    table[N] = true;
    while (N / 10) {
      max = 0;
      for (int S = 10; N / S; S *= 10) {
        tmp = (N / S) * (N % S);
        max = max > tmp ? max : tmp;
      }
      N = max;
      if (table[N]) {
        printf("-1\n");
        break;
      } else {
        table[N] = true;
        count++;
      }
    }
    if (!table[N]) {
      printf("%d\n", count);
    }
  }
  return 0;
}