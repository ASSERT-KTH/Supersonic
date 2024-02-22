#include <stdio.h>
#define N 10000
int boss[N], height[N];
int get_boss(int id) {
  if (boss[id] != id)
    boss[id] = get_boss(boss[id]);
  return boss[id];
}
void unite(int x, int y) {
  x = get_boss(x);
  y = get_boss(y);
  if (x == y)
    return;
  if (height[x] > height[y]) {
    boss[y] = x;
  } else {
    if (height[x] == height[y])
      height[y]++;
    boss[x] = y;
  }
}
int is_same(int x, int y) { return get_boss(x) == get_boss(y); }
int main() {
  int Q, command, x, y;
  scanf("%d", &Q);
  for (int i = 0; i < N; i++) {
    boss[i] = i;
    height[i] = 1;
  }
  for (int i = 0; i < Q; i++) {
    scanf("%d %d %d", &command, &x, &y);
    if (command == 0) {
      unite(x, y);
    } else {
      printf("%d\n", is_same(x, y));
    }
  }
  return 0;
}