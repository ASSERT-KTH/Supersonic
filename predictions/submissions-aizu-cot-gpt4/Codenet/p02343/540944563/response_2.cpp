#include <stdio.h>
typedef long long int ll;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000001
using namespace std;
int N;
int *boss, *height;
int get_boss(int id) {
  if (boss[id] != id)
    boss[id] = get_boss(boss[id]);
  return boss[id];
}
int is_same(int x, int y) { return get_boss(x) == get_boss(y); }
void unite(int x, int y) {
  int boss_x = get_boss(x);
  int boss_y = get_boss(y);
  if (boss_x == boss_y)
    return;
  if (height[x] > height[y]) {
    boss[boss_y] = boss_x;
  } else {
    boss[boss_x] = (height[x] < height[y]) ? boss_y : boss_x;
  }
  if(height[x] == height[y])
    height[x]++;
}
int main() {
  std::ios::sync_with_stdio(false); 
  int Q, command, x, y;
  cin >> N >> Q;
  boss = new int[N];
  height = new int[N];
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