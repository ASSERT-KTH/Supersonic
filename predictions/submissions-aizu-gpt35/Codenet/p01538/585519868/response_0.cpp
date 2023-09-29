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
  bool *table = new bool[1000001];
  for (int loop = 0; loop < Q; loop++) {
    for (int i = 0; i <= 1000000; i++)
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