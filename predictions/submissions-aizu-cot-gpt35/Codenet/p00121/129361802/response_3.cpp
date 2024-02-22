#include <stdio.h>
#include <string.h>

int bj[8];

bool vis[10000000];

struct pt {
  int ztt;
  int lwz;
  int step;
};

pt dl[1 << 16];
int front = 1, back = 1;
int bs;
int tt;

void bfs() {
  tt = 0;
  front = 1;
  back = 1;
  bs = 0;
  memset(vis, false, sizeof(vis));

  int cs = 0;
  for (int i = 0; i < 8; i++) {
    cs *= 10;
    cs += bj[i];
  }
  vis[cs] = true;

  pt lsss;
  lsss.ztt = cs;
  lsss.lwz = strchr(bj, 0) - bj;
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
    int tt = ls1.ztt;

    for (int i = 7; i >= 0; i--) {
      bj[i] = tt % 10;
      tt /= 10;
    }

    for (int i = 0; i < 4; i++) {
      lsjr.lwz = ls1.lwz + kkk[i];

      if ((ls1.lwz == 3 && lsjr.lwz == 4) || (ls1.lwz == 4 && lsjr.lwz == 3))
        continue;

      if (lsjr.lwz >= 0 && lsjr.lwz <= 7) {
        int t = bj[lsjr.lwz];
        bj[lsjr.lwz] = bj[ls1.lwz];
        bj[ls1.lwz] = t;

        lsjr.ztt = 0;
        for (int i = 0; i <= 7; i++) {
          lsjr.ztt *= 10;
          lsjr.ztt += bj[i];
        }

        t = bj[lsjr.lwz];
        bj[lsjr.lwz] = bj[ls1.lwz];
        bj[ls1.lwz] = t;

        if (!vis[lsjr.ztt]) {
          lsjr.step = ls1.step + 1;
          vis[lsjr.ztt] = true;
          dl[back] = lsjr;
          back++;
        }
      }
    }
  }
}

int main() {
  while (1) {
    if (scanf("%d", &bj[0]) == EOF) {
      return 0;
    }
    for (int i = 1; i <= 6; i++) {
      scanf("%d", &bj[i]);
    }
    scanf("%d", &bj[7]);

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