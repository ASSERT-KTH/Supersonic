#include <iostream>
#include <array>
#include <vector>

constexpr int BIG_NUM = 2000000000;
constexpr int MOD = 1000000007;
constexpr double EPS = 0.000001;

int N;
std::vector<int> boss, height;

int get_boss(int id) {
  if (boss[id] == id)
    return id;
  return boss[id] = get_boss(boss[id]);
}

bool is_same(int x, int y) { return get_boss(x) == get_boss(y); }

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
  int Q, command, x, y;
  std::cin >> N >> Q;
  boss.resize(N);
  height.resize(N);
  for (int i = 0; i < N; i++) {
    boss[i] = i;
    height[i] = 1;
  }
  for (int i = 0; i < Q; i++) {
    std::cin >> command >> x >> y;
    if (command == 0) {
      unite(x, y);
    } else {
      std::cout << is_same(x, y) << "\n";
    }
  }
  return 0;
}