#include <stdio.h>
#include <string.h>

unsigned char vis[10000000 / 8];

inline bool ck(int x) {
  return vis[x >> 3] & (1 << (x & 7));
}

inline void sb(int x) {
  vis[x >> 3] |= (1 << (x & 7));
}

inline void cb(int x) {
  vis[x >> 3] &= ~(1 << (x & 7));
}

struct pt {
  int ztt;
  int lwz;
  int step;
};

pt dl[1 << 16];
int front = 1, back = 1;
int tt;
int ddd[8] = {10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};

int bs;

void bfs() {
  tt = 0;
  front = 1;
  back = 1;
  bs = 0;
  memset(vis, 0, sizeof(vis));
  int cs;
  sscanf(bj, "%d", &cs);
  sb(cs);
  pt lsss;
  lsss.ztt = cs;
  lsss.lwz = bj[0] - '0';
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
        a = ls1.ztt / ddd[ls1.lwz] % 10;
        b = ls1.ztt / ddd[lsjr.lwz] % 10;
        lsjr.ztt = ls1.ztt + (b - a) * ddd[ls1.lwz] + (a - b) * ddd[lsjr.lwz];
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
  char bj[8];
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