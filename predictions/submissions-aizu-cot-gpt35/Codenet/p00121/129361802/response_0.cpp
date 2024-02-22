#include <stdio.h>
#include <string.h>

char zzzt[8] = {0, 1, 2, 3, 4, 5, 6, 7};
char bj[8];
bool vis[10000000];
struct pt {
  int ztt;
  int lwz;
  int step;
};
int bs;
pt dl[1 << 16];
int front = 1, back = 1;
int tt;
int ddd[8] = {10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};

void bfs() {
  tt = 0;
  front = 1;
  back = 1;
  bs = 0;
  memset(vis, false, sizeof(vis));
  int cs = atoi(bj);
  vis[cs] = true;
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
    char sss[9];
    memcpy(sss, bj, sizeof(sss));
    for (int i = 0; i < 4; i++) {
      lsjr.lwz = ls1.lwz + kkk[i];
      if ((ls1.lwz == 3 && lsjr.lwz == 4) || (ls1.lwz == 4 && lsjr.lwz == 3))
        continue;
      if (lsjr.lwz >= 0 && lsjr.lwz <= 7) {
        sss[ls1.lwz] ^= sss[lsjr.lwz];
        sss[lsjr.lwz] ^= sss[ls1.lwz];
        sss[ls1.lwz] ^= sss[lsjr.lwz];
        lsjr.ztt = 0;
        for (int i = 0; i <= 7; i++) {
          lsjr.ztt *= 10;
          lsjr.ztt += sss[i] - '0';
        }
        sss[ls1.lwz] ^= sss[lsjr.lwz];
        sss[lsjr.lwz] ^= sss[ls1.lwz];
        sss[ls1.lwz] ^= sss[lsjr.lwz];
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
  while (scanf("%s", bj) != EOF) {
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