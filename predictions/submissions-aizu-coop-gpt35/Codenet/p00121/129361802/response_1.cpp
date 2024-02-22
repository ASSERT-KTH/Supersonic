#include <algorithm>
#include <functional>
#include <set>
#include <stdio.h>
#include <vector>
using namespace std;

char zzzt[8] = {0, 1, 2, 3, 4, 5, 6, 7};
char bj[8];
vector<bool> vis(10000000);
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
  vis.assign(10000000, false);
  int cs = atoi(bj);
  vis[cs] = true;
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
    int kkk[2] = {-1, 1};
    int tt = ls1.ztt;
    for (register int i = 7; i >= 0; i--) {
      lsjr.ztt = lsjr.ztt * 10 + tt % 10;
      tt /= 10;
    }
    for (register int i = 0; i < 2; i++) {
      lsjr.lwz = ls1.lwz + kkk[i];
      if (lsjr.lwz >= 0 && lsjr.lwz <= 7) {
        swap(zzzt[lsjr.lwz], zzzt[ls1.lwz]);
        lsjr.ztt = 0;
        for (register int i = 0; i <= 7; i++) {
          lsjr.ztt = lsjr.ztt * 10 + zzzt[i];
        }
        swap(zzzt[lsjr.lwz], zzzt[ls1.lwz]);
        if (__builtin_expect(!vis[lsjr.ztt], 1)) {
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
    if (scanf("%c", &bj[0]) == EOF) {
      return 0;
    }
    scanf("%*c");
    for (int i = 1; i <= 6; i++) {
      scanf("%c%*c", &bj[i]);
    }
    scanf("%c", &bj[7]);
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