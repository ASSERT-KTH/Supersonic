#include <algorithm>
#include <bitset>
#include <functional>
#include <set>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
using namespace std;

const int TARGET = 1234567;
const int NUM_DIGITS = 8;
const int MAX_VISITED = 80000000;
const int MAX_DL = 1 << 16;
const int BFS_MOVES[4] = {-1, 1, -4, 4};

char zzzt[NUM_DIGITS] = {0, 1, 2, 3, 4, 5, 6, 7};
char bj[NUM_DIGITS];
bitset<MAX_VISITED> vis;

struct pt {
  int ztt;
  int lwz;
  int step;
};

int bs;
pt dl[MAX_DL];
int front = 1, back = 1;
int tt;
int ddd[NUM_DIGITS] = {10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};

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
    pt &ls1 = dl[front++];
    if (ls1.ztt == TARGET) {
      bs = ls1.step;
      tt = 1;
      return;
    }
    pt lsjr;
    char sss[NUM_DIGITS];
    int tt = ls1.ztt;
    for (register int i = NUM_DIGITS-1; i >= 0; --i) {
      sss[i] = tt % 10;
      tt /= 10;
    }
    for (register int i = 0; i < 4; ++i) {
      lsjr.lwz = ls1.lwz + BFS_MOVES[i];
      if ((ls1.lwz == 3 && lsjr.lwz == 4) || (ls1.lwz == 4 && lsjr.lwz == 3))
        continue;
      if (lsjr.lwz >= 0 && lsjr.lwz <= 7) {
        char t = sss[lsjr.lwz];
        sss[lsjr.lwz] = sss[ls1.lwz];
        sss[ls1.lwz] = t;
        lsjr.ztt = 0;
        for (register int i = 0; i <= 7; ++i) {
          lsjr.ztt *= 10;
          lsjr.ztt += sss[i];
        }
        t = sss[lsjr.lwz];
        sss[lsjr.lwz] = sss[ls1.lwz];
        sss[ls1.lwz] = t;
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
      return 0;
    }
    scanf("%*c");
    for (int i = 1; i <= NUM_DIGITS-2; ++i) {
      scanf("%c%*c", &bj[i]);
    }
    scanf("%c", &bj[NUM_DIGITS-1]);
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
