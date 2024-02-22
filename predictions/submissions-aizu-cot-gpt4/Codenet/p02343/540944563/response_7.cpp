#include <cstdio>
#define MAXN 100000 // Adjust this value as per your needs
int N;
int boss[MAXN], height[MAXN];

int get_boss(int id) {
  if (boss[id] != id) {
    boss[id] = get_boss(boss[id]); // path compression
  }
  return boss[id];
}

int is_same(int x, int y) { return get_boss(x) == get_boss(y); }

void unite(int x, int y) {
  x = get_boss(x);
  y = get_boss(y);
  if (x == y) return;

  if (height[x] > height[y]) {
    boss[y] = x;
  } else {
    boss[x] = y;
    if (height[x] == height[y]) {
      height[y]++;
    }
  }
}

int main() {
  int Q, command, x, y;
  scanf("%d %d", &N, &Q);
  for (int i = 0; i < N; i++) {
    boss[i] = i;
    height[i] = 0;
  }
  for (int i = 0; i < Q; i++) {
    scanf("%d %d %d", &command, &x, &y);
    if (command == 0) {
      unite(x, y);
    } else {
      printf("%d\n", is_same(x, y));
    }
  }
  return 0;
}