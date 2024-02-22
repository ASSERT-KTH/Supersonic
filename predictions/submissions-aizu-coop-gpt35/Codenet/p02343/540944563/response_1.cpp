#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
typedef long long int ll;
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
    boss[id] = get_boss(boss[id]); // Path compression
    return boss[id];
  }
}
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
  cin >> N >> Q; // Faster I/O using cin
  boss.resize(N);
  height.resize(N);
  for (int i = 0; i < N; i++) {
    boss[i] = i;
    height[i] = 1;
  }
  for (int i = 0; i < Q; i++) {
    cin >> command >> x >> y; // Faster I/O using cin
    if (command == 0) {
      unite(x, y);
    } else {
      if (get_boss(x) == get_boss(y)) { // Compare the root parents directly
        cout << "1\n"; // Faster I/O using cout
      } else {
        cout << "0\n"; // Faster I/O using cout
      }
    }
  }
  return 0;
}