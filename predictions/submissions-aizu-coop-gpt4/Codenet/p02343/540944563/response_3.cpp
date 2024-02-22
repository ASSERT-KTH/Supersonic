#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> boss, height;

int get_boss(int id) {
  if (boss[id] != id)
    boss[id] = get_boss(boss[id]);
  return boss[id];
}

void unite(int x, int y) {
  int boss_x = get_boss(x);
  int boss_y = get_boss(y);

  if (boss_x == boss_y)
    return;

  if (height[x] > height[y]) {
    boss[boss_y] = boss_x;
  } else {
    if (height[x] == height[y])
      height[x]++;
    boss[boss_x] = boss_y;
  }
}

bool is_same(int x, int y) {
  return get_boss(x) == get_boss(y);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int Q, command, x, y;
  cin >> N >> Q;

  boss.resize(N);
  height.resize(N, 1);
  for (int i = 0; i < N; i++) {
    boss[i] = i;
  }

  for (int i = 0; i < Q; i++) {
    cin >> command >> x >> y;
    if (command == 0) {
      unite(x, y);
    } else {
      cout << is_same(x, y) << "\n";
    }
  }

  return 0;
}