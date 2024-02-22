#include <stdio.h>
#include <stdlib.h>
typedef int bool;
#define true 1
#define false 0

int N;
int *boss, *height;

inline int get_boss(int id) {
  return boss[id] == id ? id : (boss[id] = get_boss(boss[id]));
}

inline bool is_same(int x, int y) {
  return get_boss(x) == get_boss(y);
}

inline void unite(int x, int y) {
  int boss_x = get_boss(x);
  int boss_y = get_boss(y);

  if (boss_x != boss_y) {
    if (height[boss_x] > height[boss_y]) {
      boss[boss_y] = boss_x;
    } else {
      boss[boss_x] = boss_y;
      if (height[boss_x] == height[boss_y]) {
        height[boss_y]++;
      }
    }
  }
}

int main() {
  int Q, command, x, y;
  scanf("%d %d", &N, &Q);
  boss = (int*)malloc(N * sizeof(int));
  height = (int*)malloc(N * sizeof(int));
  for (int i = 0; i < N; i++) {
    boss[i] = i;
    height[i] = 0;
  }
  for (int i = 0; i < Q; i++) {
    scanf("%d %d %d", &command, &x, &y);
    if (command == 0) {
      unite(x, y);
    } else {
      printf(is_same(x, y) ? "1\n" : "0\n");
    }
  }
  
  free(boss);
  free(height);

  return 0;
}