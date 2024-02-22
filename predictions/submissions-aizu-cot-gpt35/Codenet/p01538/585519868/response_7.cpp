#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <stdio.h>
#include <vector>
using namespace std;

int main() {
  int Q, N, count, tmp, S;
  scanf("%d", &Q);
  vector<bool> table;
  table.reserve(1000001);
  
  for (int loop = 0; loop < Q; loop++) {
    count = 0;
    scanf("%d", &N);
    table.assign(1000001, false);
    table[N] = true;
    
    while (true) {
      int max = 0;
      for (S = 10; N / S != 0; S *= 10) {
        tmp = (N / S) * (N % S);
        max = (max >= tmp) ? max : tmp;
      }
      N = max;
      
      if (table[N]) {
        printf("-1\n");
        break;
      } else {
        table[N] = true;
        count++;
      }
      
      if (N / 10 == 0)
        break;
    }
    
    if (N / 10 != 0) {
      printf("%d\n", count);
    }
  }
  
  return 0;
}