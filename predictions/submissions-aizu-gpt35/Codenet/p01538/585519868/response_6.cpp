#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <stdio.h>
#include <vector>
using namespace std;
const int MAX_N = 1000000;
int main() {
  int Q, N, count, tmp, max, S;
  bool FLG;
  scanf("%d", &Q);
  bool *table = new bool[MAX_N + 1];
  for (int loop = 0; loop < Q; loop++) {
    for (int i = 0; i <= MAX_N; i++)
      table[i] = false;
    count = 0;
    scanf("%d", &N);
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
      if (table[N] == true) {
        FLG = true;
        break;
      } else {
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
  delete[] table;
  return 0;
}
