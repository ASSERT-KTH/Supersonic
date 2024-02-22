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
    vector<int> modified_indices;
    count = 0;
    scanf("%d", &N);
    table[N] = true;
    modified_indices.push_back(N);
    FLG = false;
    while (true) {
      if (N / 10 == 0)
        break;
      max = 0;
      int most_sig = N, least_sig = 1;
      for (S = 10; N / S != 0; S *= 10) {
        most_sig = N / S;
        least_sig = N % S;
        tmp = most_sig * least_sig;
        max = (max >= tmp) ? max : tmp;
      }
      N = max;
      if (table[N] == true) {
        FLG = true;
        break;
      } else {
        table[N] = true;
        modified_indices.push_back(N);
        count++;
      }
    }
    if (FLG) {
      printf("-1\n");
    } else {
      printf("%d\n", count);
    }
    for (int index : modified_indices) {
      table[index] = false;
    }
  }
  return 0;
}