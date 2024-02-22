#include <stdio.h>
#include <bitset>

char zzzt[8] = {0, 1, 2, 3, 4, 5, 6, 7};
char bj[8];
std::bitset<12345679> vis;
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
  vis.reset();
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
    const int kkk[4] = {-1, 1, -4, 4};
    int tt = ls1.ztt;
    for (register int i = 7; i >= 0; i--) {
      bj[i] = tt % 10;
      tt /= 10;
    }
    for (register int i = 0; i < 4; i++) {
      lsjr.lwz = ls1.lwz + kkk[i];
      if (abs(lsjr.lwz - ls1.lwz) == 1) continue;
      if (lsjr.lwz >= 0 && lsjr.lwz <= 7) {
        char t = bj[lsjr.lwz];
        bj[lsjr.lwz] = bj[ls1.lwz];
        bj[ls1.lwz] = t;
        lsjr.ztt = 0;
        for (register int i = 0; i <= 7; i++) {
          lsjr.ztt *= 10;
          lsjr.ztt += bj[i];
        }
        t = bj[lsjr.lwz];
        bj[lsjr.lwz] = bj[ls1.lwz];
        bj[ls1.lwz] = t;
        if (!vis[lsjr.ztt]) {
          lsjr.step = ls1.step + 1;
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
    if (scanf("%c", &bj[0]) == EOF) {
      break;
    }
    scanf("%*c");
    for (int i = 1; i <= 6; i++) {
      scanf("%c%*c", &bj[i]);
    }
    scanf("%c", &bj[7]);
    bfs();
    if (tt) {
      puts(std::to_string(bs).c_str());
    } else {
      puts("-1");
    }
    while (getchar() != '\n')
      ;
  }
}