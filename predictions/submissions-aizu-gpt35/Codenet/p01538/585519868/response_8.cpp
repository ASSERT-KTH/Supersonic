#include <cstdio>
#include <cstring>
const int MAXN = 1e6 + 5;
bool table[MAXN];
int main() {
  int Q, N;
  scanf("%d", &Q);
  while (Q--) {
    scanf("%d", &N);
    memset(table, false, sizeof(table));
    table[N] = true;
    int cnt = 0;
    bool FLG = false;
    while (true) {
      if (N < 10) break;
      int S = 10, tmp, max = 0;
      while (N / S) {
        tmp = (N / S) * (N % S);
        max = (max > tmp) ? max : tmp;
        S *= 10;
      }
      N = max;
      if (table[N]) {
        FLG = true;
        break;
      } else {
        table[N] = true;
        cnt++;
      }
    }
    if (FLG)
      printf("-1\n");
    else
      printf("%d\n", cnt);
  }
  return 0;
}