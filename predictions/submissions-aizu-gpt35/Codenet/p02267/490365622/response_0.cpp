#include <stdio.h>
int main() {
  int n, S[10000], q, T[500], i, j, cnt = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", &S[i]);
  scanf("%d", &q);
  for (j = 0; j < q; j++)
    scanf("%d", &T[j]);
  for (i = 0; i < q; i++)
  {
    for (j = 0; j < n; j+=8)
    {
      if (T[i] == S[j]) {
        cnt++;
        break;
      }
      if (T[i] == S[j+1]) {
        cnt++;
        break;
      }
      if (T[i] == S[j+2]) {
        cnt++;
        break;
      }
      if (T[i] == S[j+3]) {
        cnt++;
        break;
      }
      if (T[i] == S[j+4]) {
        cnt++;
        break;
      }
      if (T[i] == S[j+5]) {
        cnt++;
        break;
      }
      if (T[i] == S[j+6]) {
        cnt++;
        break;
      }
      if (T[i] == S[j+7]) {
        cnt++;
        break;
      }
    }
  }
  printf("%d\n", cnt);
  return 0;
}
