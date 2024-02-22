#include <cstdio>
#include <vector>

using namespace std;

int get_boss(int id, vector<int>& boss) {
  if (boss[id] == id) {
    return id;
  } else {
    return boss[id] = get_boss(boss[id], boss);
  }
}

bool is_same(int x, int y, vector<int>& boss) { 
  return get_boss(x, boss) == get_boss(y, boss); 
}

void unite(int x, int y, vector<int>& boss, vector<int>& height) {
  int boss_x = get_boss(x, boss);
  int boss_y = get_boss(y, boss);
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
  int N, Q, command, x, y;
  scanf("%d %d", &N, &Q);
  vector<int> boss(N);
  vector<int> height(N, 1);
  for (int i = 0; i < N; i++) {
    boss[i] = i;
  }
  for (int i = 0; i < Q; i++) {
    scanf("%d %d %d", &command, &x, &y);
    if (command == 0) {
      unite(x, y, boss, height);
    } else {
      printf(is_same(x, y, boss) ? "1\n" : "0\n");
    }
  }
  return 0;
}