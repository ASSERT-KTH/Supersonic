#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <stdio.h>
using namespace std;
int main() {
  int Q, N, count, max;
  bool FLG;
  scanf("%d", &Q);
  for (int loop = 0; loop < Q; loop++) {
    unordered_set<int> table;
    count = 0;
    scanf("%d", &N);
    table.insert(N);
    FLG = false;
    int S = 10;
    while (N / 10 != 0) {
      max = (N / S) * (N % S);
      N = max;
      if (table.find(N) != table.end()) {
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