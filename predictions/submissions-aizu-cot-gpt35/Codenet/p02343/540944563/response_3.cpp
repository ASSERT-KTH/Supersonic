#include <algorithm>
#include <iostream>
#include <vector>

const int MOD = 1000000007;

int get_boss(std::vector<int>& boss, int id) {
  int root = id;
  while (root != boss[root]) {
    root = boss[root];
  }
  while (id != root) {
    int next = boss[id];
    boss[id] = root;
    id = next;
  }
  return root;
}

bool is_same(std::vector<int>& boss, int x, int y) {
  return get_boss(boss, x) == get_boss(boss, y);
}

void unite(std::vector<int>& boss, std::vector<int>& height, int x, int y) {
  int boss_x = get_boss(boss, x);
  int boss_y = get_boss(boss, y);
  if (boss_x == boss_y) {
    return;
  }
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
  int N, Q;
  std::cin >> N >> Q;
  
  std::vector<int> boss(N);
  std::vector<int> height(N, 1);
  for (int i = 0; i < N; i++) {
    boss[i] = i;
  }
  
  for (int i = 0; i < Q; i++) {
    int command, x, y;
    std::cin >> command >> x >> y;
    if (command == 0) {
      unite(boss, height, x, y);
    } else {
      std::cout << is_same(boss, x, y) << std::endl;
    }
  }
  
  return 0;
}