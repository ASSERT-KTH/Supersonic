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
  fill(table, table + 1000001, false);  // Initialize the table once
  for (int loop = 0; loop < Q; loop++) {
    count = 0;
    scanf("%d", &N);
    table[N] = true;
    FLG = false;
    while (N >= 10) {  // Avoiding division here
      int num_digits = log10(N) + 1;  // Calculating number of digits in N
      S = pow(10, num_digits / 2);  // Calculating the divisor using number of digits
      tmp = (N / S) * (N % S);
      max = (max >= tmp) ? max : tmp;
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
    fill(table, table + 1000001, false);  // Reset the used entries to false for the next iteration
  }
  delete[] table;  // Free the dynamically allocated memory
  return 0;
}