#include <stdio.h>
#include <string.h>

char bj[8];
char vis[8];

#define ck(x) (vis[(x) >> 3] & (1 << ((x)&7)))
#define sb(x) (vis[(x) >> 3] |= (1 << ((x)&7)))
#define cb(x) (vis[(x) >> 3] &= ~(1 << ((x)&7)))

struct pt {
  int ztt;
  int lwz;
  int step;
};

pt dl[1 << 16];
int front = 1;
int tt;

void bfs() {
  tt = 0;
  front = 1;
  int back = 1;
  memset(vis, 0, sizeof(vis));

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
  while (fgets(bj, sizeof(bj), stdin) != NULL) {
    bfs();

    if (tt) {
      printf("%d\n", dl[back - 1].step);
    } else {
      printf("-1\n");
    }
  }

  return 0;
}