#include <stdio.h>
#include <unordered_set>

int main() {
  int Q;
  scanf("%d", &Q);
  
  std::unordered_set<int> table;
  
  for (int loop = 0; loop < Q; loop++) {
    table.clear();
    int count = 0;
    int N;
    scanf("%d", &N);
    table.insert(N);
    bool FLG = false;
    while (N >= 10) {
      int max = 0;
      for (int S = 10; N / S != 0; S *= 10) {
        int tmp = (N / S) * (N % S);
        max = std::max(max, tmp);
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