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
  scanf("%d", &Q);
  for (int loop = 0; loop < Q; loop++) {
    unordered_set<int> table;
    count = 0;
    scanf("%d", &N);
    if (N < 10) { // Check if N is a single-digit number
      printf("0\n");
      continue;
    }
    table.insert(N);
    while (true) {
      max = 0;
      for (S = 10; N / S != 0; S *= 10) {
        tmp = (N / S) * (N % S);
        max = (max >= tmp) ? max : tmp;
      }
      N = max;
      if (table.find(N) != table.end()) {
        printf("-1\n");
        break;
      } else {
        table.insert(N);
        count++;
      }
    }
    if (table.find(N) == table.end()) { // If N was not found in the set
      printf("%d\n", count);
    }
  }
  return 0;
}