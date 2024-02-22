#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <stdio.h>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
  int Q, N, count, tmp, max, S;
  bool FLG;
  scanf("%d", &Q);
  unordered_set<int> table;
  for (int loop = 0; loop < Q; loop++) {
    table.clear();
    count = 0;
    scanf("%d", &N);
    table.insert(N);
    FLG = false;
    while (true) {
      if (N / 10 == 0)
        break;
      max = 0;
      int digits = log10(N) + 1;
      for (S = pow(10, digits - 1); S >= 10; S /= 10) {
        tmp = (N / S) * (N % S);
        max = (max >= tmp) ? max : tmp;
      }
      N = max;
      if (table.count(N) > 0) {
        FLG = true;
        break;
      } else {
        table.insert(N);
        count++;
      }
    }
    if (FLG) {
      printf("-1\n");
    } else {
      printf("%d\n", count);
    }
  }
  return 0;
}