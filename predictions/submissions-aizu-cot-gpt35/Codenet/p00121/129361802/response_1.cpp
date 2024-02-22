#include <stdio.h>
#include <string.h>

char bj[8];
int vis[10000000];
struct pt {
  int ztt;
  int lwz;
  int step;
};
int bs;
pt dl[40320];
int front = 1, back = 1;
int tt;
int ddd[8] = {10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};
int kkk[4] = {-1, 1, -4, 4};

void bfs() {
  tt = 0;
  front = 1;
  back = 1;
  bs = 0;
  memset(vis, 0, sizeof(vis));
  int cs = atoi(bj);
  vis[cs] = 1;
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
    int tt = ls1.ztt;
    for (int i = 7; i > 0; i--) {
      int sss = tt / ddd[i];
      tt %= ddd[i];
      if (sss == 0) {
        sss = tt;
        tt = 0;
      }
      int t = sss;
      lsjr.ztt = ls1.ztt - sss * ddd[i] + sss * ddd[ls1.lwz];
      lsjr.lwz = ls1.lwz + kkk[i % 4];
      if ((ls1.lwz == 3 && lsjr.lwz == 4) || (ls1.lwz == 4 && lsjr.lwz == 3))
        continue;
      if (lsjr.lwz > 0 && lsjr.lwz <= 7 && !vis[lsjr.ztt]) {
        vis[lsjr.ztt] = 1;
        lsjr.step = ls1.step + 1;
        dl[back] = lsjr;
        back++;
      }
      ls1.ztt = ls1.ztt - sss * ddd[ls1.lwz] + t * ddd[ls1.lwz];
    }
  }
}

int main() {
  while (1) {
    if (getchar() == EOF) {
      return 0;
    }
    for (int i = 0; i <= 7; i++) {
      scanf("%c", &bj[i]);
      if (i != 7) {
        getchar(); // Skip the separator character
      }
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