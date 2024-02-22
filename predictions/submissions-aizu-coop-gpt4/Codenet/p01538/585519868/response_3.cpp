#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <stdio.h>
#include <vector>
using namespace std;
int main() {
  int Q, N, count, tmp, max, S;
  scanf("%d", &Q);
  bool table[1000001] = {false};  // stack allocation
  vector<int> visited;  // to keep track of visited numbers
  for (int loop = 0; loop < Q; loop++) {
    count = 0;
    scanf("%d", &N);
    table[N] = true;
    visited.push_back(N);
    while (N / 10 > 0) {  // simplified condition
      max = 0;
      for (S = 10; N / S != 0; S *= 10) {
        int div = N / S;
        int mod = N % S;
        tmp = div * mod;
        max = (max >= tmp) ? max : tmp;
      }
      N = max;
      if (table[N]) {
    	  printf("-1\n");
    	  break;
      } else {
        table[N] = true;
        visited.push_back(N);
        count++;
      }
    }
    if (N / 10 == 0) {
      printf("%d\n", count);
    }
    // reset visited numbers to false
    for (int i : visited) {
      table[i] = false;
    }
    visited.clear();
  }
  return 0;
}