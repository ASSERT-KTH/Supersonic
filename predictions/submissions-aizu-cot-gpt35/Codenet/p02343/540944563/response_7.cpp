#include <cstdio>
#include <vector>

int N, Q;
std::vector<int> boss, height;

int get_boss(int id) {
  if (boss[id] == id)
    return id;
  else
    return boss[id] = get_boss(boss[id]);
}

bool is_same(int x, int y) {
  return get_boss(x) == get_boss(y);
}

void unite(int x, int y) {
  int boss_x = get_boss(x);
  int boss_y = get_boss(y);
  if (boss_x == boss_y)
    return;
  if (height[x] > height[y]) {
    boss[boss_y] = boss_x;
  } else if (height[x] < height[y]) {
    boss[boss_x] = boss_y;
  } else {
    boss[boss_y] = boss_x;
    height[x]++;
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  scanf("%d %d", &N, &Q);

  boss.resize(N + 1);
  height.resize(N + 1);

  for (int i = 1; i <= N; i++) {
    boss[i] = i;
    height[i] = 1;
  }

  for (int i = 0; i < Q; i++) {
    int command, x, y;
    scanf("%d %d %d", &command, &x, &y);
    if (command == 0) {
      unite(x, y);
    } else {
      printf("%d\n", is_same(x, y) ? 1 : 0);
    }
  }

  return 0;
}