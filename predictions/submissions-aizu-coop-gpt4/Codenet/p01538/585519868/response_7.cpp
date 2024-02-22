#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <stdio.h>
#include <vector>
using namespace std;

bool table[1000001]; // Declare the table as a global variable

int main() {
  int Q, N, count, tmp, max, S;
  bool FLG;
  scanf("%d", &Q);
  for (int loop = 0; loop < Q; loop++) {
    count = 0;
    scanf("%d", &N);
    table[N] = true;
    FLG = false;
    while (true) {
      if (N / 10 == 0)
        break;
      max = 0;
      for (S = 10; N / S != 0; S *= 10) {
        int N_div_S = N / S;
        int N_mod_S = N % S;
        tmp = N_div_S * N_mod_S;
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
    for (int i = 0; i <= N; i++) // Reset the visited elements
      table[i] = false;
  }
  return 0;
}