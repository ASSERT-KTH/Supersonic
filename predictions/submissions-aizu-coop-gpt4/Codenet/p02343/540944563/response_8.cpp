#include <iostream>
#include <vector>
using namespace std;
int N;
vector<int> boss, height;

// Suggest compiler to inline these functions
inline int get_boss(int id) {
  if (boss[id] == id)
    return id;
  else {
    return boss[id] = get_boss(boss[id]);
  }
}
inline bool is_same(int x, int y) { return get_boss(x) == get_boss(y); }

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
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); // Fast I/O
  int Q, command, x, y;
  cin >> N >> Q;
  boss.resize(N); // Use vector instead of dynamic allocation
  height.resize(N); // Use vector instead of dynamic allocation
  for (int i = 0; i < N; i++) {
    boss[i] = i;
    height[i] = 1;
  }
  for (int i = 0; i < Q; i++) {
    cin >> command >> x >> y;
    if (command == 0) {
      unite(x, y);
    } else {
      if (is_same(x, y)) {
        cout << "1\n";
      } else {
        cout << "0\n";
      }
    }
  }
  return 0;
}