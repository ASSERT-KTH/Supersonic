#include <iostream>
#include <vector>

const int BIG_NUM = 2000000000;
const int MOD = 1000000007;
const double EPS = 0.000001;

int N;
std::vector<int> boss, height;

int get_boss(int id) {
  if (boss[id] == id)
    return id;
  else {
    return boss[id] = get_boss(boss[id]);
  }
}

int is_same(int x, int y) { return get_boss(x) == get_boss(y); }

void unite(int& x, int& y) {
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
      if (is_same(x, y)) {
        std::cout << "1\n";
      } else {
        std::cout << "0\n";
      }
    }
  }

  return 0;
}