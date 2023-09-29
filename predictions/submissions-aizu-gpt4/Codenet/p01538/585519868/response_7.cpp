#include <cstdio>
#include <vector>
using namespace std;
int main() {
  int Q, N, tmp, max, S;
  scanf("%d", &Q);
  vector<bool> table(1000001, false);
  for (int loop = 0; loop < Q; loop++) {
    fill(table.begin(), table.end(), false);
    int count = 0;
    scanf("%d", &N);
    table[N] = true;
    bool FLG = false;
    while (N / 10 != 0) {
      max = 0;
      for (S = 10; N / S != 0; S *= 10) {
        tmp = (N / S) * (N % S);
        if (tmp > max)
          max = tmp;
      }
      N = max;
      if (table[N]) {
        FLG = true;
        break;
      } else {
        table[N] = true;
        count++;
      }
    }
    printf(FLG ? "-1\n" : "%d\n", count);
  }
  return 0;
}