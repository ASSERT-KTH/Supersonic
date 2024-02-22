#include <cstdio>
int main() {
  int a, b, n, way[289];
  while (scanf("%d %d", &a, &b), a || b) {
    scanf("%d", &n);
    for (int i = 0; i <= b; i++) {
      for (int j = 0; j <= a; j++)
        way[i*a + j] = -1;
    }
    for (int i = 0; i < n; i++) {
      int t1, t2;
      scanf("%d %d", &t1, &t2);
      way[t2*a + t1] = -1;
    }

    way[a + 1] = 1;
    for (int i = 2; i <= a; i++) {
      if (way[i] == -1)
        break;
      way[i] = 1;
    }
    for (int i = 2; i <= b; i++) {
      if (way[i*a + 1] == -1)
        break;
      way[i*a + 1] = 1;
    }
    for (int i = 2; i <= b; i++) {
      for (int j = 2; j <= a; j++) {
        if (way[i*a + j] != -1) {
          int w = 0, h = 0;
          if (way[i*a + j - 1] != -1)
            w = way[i*a + j - 1];
          if (way[(i-1)*a + j] != -1)
            h = way[(i-1)*a + j];
          way[i*a + j] = w + h;
        }
      }
    }
    printf("%d\n", way[b*a + a]);
  }
  return 0;
}