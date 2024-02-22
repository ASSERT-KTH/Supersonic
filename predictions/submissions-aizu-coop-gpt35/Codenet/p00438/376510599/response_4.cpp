#include <cstdio>

int main() {
  int a, b, n, t1, t2;
  while (scanf("%d %d", &a, &b), a || b) {
    scanf("%d", &n);
    int size = (a + 1) * (b + 1);
    int* way = new int[size];
    for (int i = 0; i < size; i++) {
      way[i] = 0;
    }
    for (int i = 0; i < n; i++) {
      scanf("%d %d", &t1, &t2);
      way[t2 * (a + 1) + t1] = -1;
    }
    for (int i = 1; i <= a; i++) {
      if (way[i] == -1 || way[b * (a + 1) + i] == -1) {
        break;
      }
      way[i] = 1;
      way[b * (a + 1) + i] = 1;
    }
    for (int i = 2; i <= b; i++) {
      for (int j = 2; j <= a; j++) {
        if (way[i * (a + 1) + j] != -1) {
          int w = 0, h = 0;
          if (way[i * (a + 1) + j - 1] != -1) {
            w = way[i * (a + 1) + j - 1];
          }
          if (way[(i - 1) * (a + 1) + j] != -1) {
            h = way[(i - 1) * (a + 1) + j];
          }
          way[i * (a + 1) + j] = w + h;
        }
      }
    }
    printf("%d\n", way[b * (a + 1) + a]);
    delete[] way;
  }
  return 0;
}