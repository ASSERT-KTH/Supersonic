#include <cstdio>
int main() {
  int a, b, n, t1, t2, way[17];
  while (scanf("%d %d", &a, &b), a || b) {
    scanf("%d", &n);
    for (int i = 1; i <= a; i++)
      way[i] = -1;
    for (int i = 0; i < n; i++) {
      scanf("%d %d", &t1, &t2);
      if(t2 == 1) way[t1] = 0;
    }
    way[1] = 1;
    for (int i = 2; i <= a; i++)
      if (way[i] != 0) way[i] = way[i - 1];
    for (int i = 2; i <= b; i++) {
      for (int j = 1; j <= a; j++)
        way[j] = (way[j-1] != 0 && way[j] != 0) ? way[j] + way[j - 1] : 0;
    }
    printf("%d\n", way[a]);
  }
  return 0;
}