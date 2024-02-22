#include <stdio.h>
#include <vector>

int N;

std::vector<int> boss, height;

int get_boss(int id) {
  if (boss[id] == id)
    return id;
  else {
    boss[id] = get_boss(boss[id]); // Path compression
    return boss[id];
  }
}

bool is_same(int x, int y) { return get_boss(x) == get_boss(y); }

void unite(int x, int y) {
  int boss_x = get_boss(x);
  int boss_y = get_boss(y);
  if (boss_x == boss_y)
    return;
  if (height[boss_x] > height[boss_y]) {
    boss[boss_y] = boss_x;
  } else if (height[boss_x] < height[boss_y]) {
    boss[boss_x] = boss_y;
  } else {
    boss[boss_y] = boss_x;
    height[boss_x]++;
  }
}

int main() {
  int Q, command, x, y;
  scanf("%d %d", &N, &Q);
  boss.resize(N);
  height.resize(N);
  for (int i = 0; i < N; i++) {
    boss[i] = i;
    height[i] = 1;
  }
  for (int i = 0; i < Q; i++) {
    scanf("%d %d %d", &command, &x, &y);
    if (command == 0) {
      unite(x, y);
    } else {
      if (is_same(x, y)) {
        printf("1\n");
      } else {
        printf("0\n");
      }
    }
  }
  return 0;
}