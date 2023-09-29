#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000001
using namespace std;
int N;
vector<int> boss, height;
int get_boss(int id) {
  if (boss[id] == id)
    return id;
  else {
    return boss[id] = get_boss(boss[id]);
  }
}
int is_same(int x, int y) { return get_boss(x) == get_boss(y); }
void unite(int x, int y) {
  int boss_x = get_boss(x);
  int boss_y = get_boss(y);
  if (boss_x != boss_y) {
    if (height[boss_x] < height[boss_y]) {
      swap(boss_x, boss_y);
    }
    boss[boss_y] = boss_x;
    if (height[boss_x] == height[boss_y]) height[boss_x]++;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int Q, command, x, y;
  cin >> N >> Q;
  boss.resize(N);
  height.resize(N);
  for (int i = 0; i < N; i++) {
    boss[i] = i;
    height[i] = 1;
  }
  for (int i = 0; i < Q; i++) {
    cin >> command >> x >> y;
    if (command == 0) {
      unite(x, y);
    } else {
      cout << is_same(x, y) << endl;
    }
  }
  return 0;
}