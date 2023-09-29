#include <algorithm>
#include <bitset>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
char bj[8];
bitset<80000000> vis;
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
  vis.reset();
  int cs = atoi(bj);
  vis[cs] = 1;
  pt lsss;
  lsss.ztt = cs;
  lsss.lwz = strchr(bj, '0') - bj;
  lsss.step = 0;
  dl[back++] = lsss;
  while (front < back) {
    pt ls1 = dl[front++];
    if (ls1.ztt == 1234567) {
      bs = ls1.step;
      tt = 1;
      return;
    }
    pt lsjr;
    int kkk[4] = {-1, 1, -4, 4};
    char sss[9];
    int tt = ls1.ztt;
    for (int i = 7; i >= 0; i--) {
      sss[i] = tt % 10;
      tt /= 10;
    }
    for (int i = 0; i < 4; i++) {
      lsjr.lwz = ls1.lwz + kkk[i];
      if ((ls1.lwz == 3 && lsjr.lwz == 4) || (ls1.lwz == 4 && lsjr.lwz == 3))
        continue;
      if (lsjr.lwz >= 0 && lsjr.lwz <= 7) {
        swap(sss[lsjr.lwz], sss[ls1.lwz]);
        lsjr.ztt = 0;
        for (int i = 0; i <= 7; i++) {
          lsjr.ztt = lsjr.ztt * 10 + sss[i];
        }
        swap(sss[lsjr.lwz], sss[ls1.lwz]);
        if (!vis[lsjr.ztt]) {
          lsjr.step = ls1.step + 1;
          vis[lsjr.ztt] = 1;
          dl[back++] = lsjr;
        }
      }
    }
  }
}
int main() {
  while (scanf("%s", bj) == 1) {
    bfs();
    printf(tt ? "%d\n" : "-1\n", bs);
  }
  return 0;
}