#include <cstdio>
using namespace std;
constexpr int BIG_NUM = 2000000000;
constexpr int MOD = 1000000007;
constexpr double EPS = 0.000001;
int N;
int *boss, *height;
int get_boss(int id) {
  return boss[id] == id ? id : (boss[id] = get_boss(boss[id]));
}
bool is_same(int x, int y) { return get_boss(x) == get_boss(y); }
void unite(int x, int y) {
  int boss_x = get_boss(x);
  int boss_y = get_boss(y);
  if (boss_x != boss_y) {
    if (height[x] > height[y]) {
      boss[boss_y] = boss_x;
    } else {
      boss[boss_x] = boss_y;
      if (height[x] == height[y]) height[x]++;
    }
  }
}
int main() {
  int Q, command, x, y;
  scanf("%d %d", &N, &Q);
  boss = new int[N];
  height = new int[N];
  for (int i = 0; i < N; i++) {
    boss[i] = i;
    height[i] = 0;
  }
  while(Q--) {
    scanf("%d %d %d", &command, &x, &y);
    if (command == 0) {
      unite(x, y);
    } else {
      printf("%d\n", is_same(x, y));
    }
  }
  delete[] boss;
  delete[] height;
  return 0;
}