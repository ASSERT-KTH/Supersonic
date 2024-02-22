#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

typedef long long int ll;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000001

const int MAX_N = 100000;

int N;
int boss[MAX_N], height[MAX_N];

int get_boss(int id) {
  int parent = boss[id];
  while (parent != id) {
    id = parent;
    parent = boss[id];
  }
  return id;
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
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int Q, command, x, y;
  std::cin >> N >> Q;

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