#include <stdio.h>
#include <string.h>
#include <set>
using namespace std;

char bj[8];
char vis[80000000 / 8];
#define ck(x) (visited.find(x) != visited.end())
#define sb(x) (visited.insert(x))
#define cb(x) (visited.erase(x))

struct pt {
  int ztt;
  int lwz;
  int step;
};

int bs;
pt dl[1 << 16];
int front = 1, back = 1;
int tt;

void bfs() {
  tt = 0;
  front = 1;
  back = 1;
  bs = 0;
  memset(vis, 0, sizeof(vis));
  set<int> visited;
  int cs = atoi(bj);
  sb(cs);
  pt lsss;
  lsss.ztt = cs;
  lsss.lwz = strchr(bj, '0') - bj;
  lsss.step = 0;
  dl[back] = lsss;
  back++;
  while (front < back) {
    pt ls1 = dl[front];
    front++;
    if (ls1.ztt == 1234567) {
      bs = ls1.step;
      tt = 1;
      return;
    }
    pt lsjr;
    int kkk[4] = {-1, 1, -4, 4};
    for (int i = 0; i < 4; i++) {
      lsjr.lwz = ls1.lwz + kkk[i];
      if ((ls1.lwz == 3 && lsjr.lwz == 4) || (ls1.lwz == 4 && lsjr.lwz == 3))
        continue;
      if (lsjr.lwz >= 0 && lsjr.lwz <= 7) {
        int a, b;
        a = ls1.ztt / 1000000 % 10;
        b = ls1.ztt / 10000 % 10;
        lsjr.ztt = ls1.ztt + (b - a) * 1000000 + (a - b) * 10000;
        if (!ck(lsjr.ztt)) {
          lsjr.step = ls1.step + 1;
          sb(lsjr.ztt);
          dl[back] = lsjr;
          back++;
        }
      }
    }
  }
}

int main() {
  while (fgets(bj, sizeof(bj), stdin)) {
    bfs();
    if (tt) {
      printf("%d\n", bs);
    } else {
      printf("-1\n");
    }
    while (getchar() != '\n')
      ;
  }
  return 0;
}