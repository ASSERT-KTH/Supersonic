#include <stdio.h>
#include <bitset>

struct pt {
  int ztt;
  int lwz;
  int step;
};

pt dl[1 << 16];
int front = 1, back = 1;
int tt;
int ddd[8] = {10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};

void bfs() {
  tt = 0;
  front = 1;
  back = 1;
  int bs = 0;
  std::bitset<10000000> vis;
  vis.reset();

  int cs;
  scanf("%d", &cs);
  vis[cs] = 1;
  pt lsss;
  lsss.ztt = cs;
  lsss.lwz = cs % 10;
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
      int digit = tt % 10;
      lsjr.ztt += digit * ddd[i];
      tt /= 10;
    }

    for (int i = 0; i < 4; i++) {
      lsjr.lwz = ls1.lwz + kkk[i];

      if (lsjr.lwz >= 0 && lsjr.lwz <= 7) {
        int t = (lsjr.ztt / ddd[lsjr.lwz]) % 10;
        lsjr.ztt -= t * ddd[lsjr.lwz];
        lsjr.ztt += t * ddd[ls1.lwz];
        lsjr.step = ls1.step + 1;

        if (!vis[lsjr.ztt]) {
          vis[lsjr.ztt] = 1;
          dl[back] = lsjr;
          back++;
        }
      }
    }
  }
}

int main() {
  while (1) {
    int bj;
    if (scanf("%d", &bj) == EOF) {
      return 0;
    }

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