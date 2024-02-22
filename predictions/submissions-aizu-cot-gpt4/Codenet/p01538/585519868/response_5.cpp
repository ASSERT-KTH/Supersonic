#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
int main() {
  int Q, N, count, tmp, max, S;
  scanf("%d", &Q);
  for (int loop = 0; loop < Q; loop++) {
    scanf("%d", &N);
    vector<bool> table(N + 1, false);
    table[N] = true;
    count = 0;
    while (N / 10 != 0) {
      max = 0;
      for (S = 10; N / S != 0; S *= 10) {
        tmp = (N / S) * (N % S);
        max = std::max(max, tmp);
      }
      N = max;
      if (table[N]) {
        printf("-1\n");
        break;
      }
      table[N] = true;
      count++;
    }
    if (N / 10 == 0) {
      printf("%d\n", count);
    }
  }
  return 0;
}