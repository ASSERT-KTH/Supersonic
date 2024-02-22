#include <algorithm>
#include <unordered_set>
#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;

char zzzt[8] = {0, 1, 2, 3, 4, 5, 6, 7};
char bj[8];
unordered_set<int> vis;

struct pt {
  int ztt;
  int lwz;
  int step;
};

int bs;
queue<pt> dl;
int tt;
int ddd[8] = {10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};

void bfs(int cs, int lwz) {
  tt = 0;
  bs = 0;
  vis.clear();
  vis.insert(cs);

  pt lsss;
  lsss.ztt = cs;
  lsss.lwz = lwz;
  lsss.step = 0;

  dl.push(lsss);

  while (!dl.empty()) {
    pt ls1 = dl.front();
    dl.pop();
    if (ls1.ztt == 1234567) {
      bs = ls1.step;
      tt = 1;
      return;
    }

    pt lsjr;
    int kkk[4] = {-1, 1, -4, 4};
    char sss[9];
    int tt = ls1.ztt;
    for (register int i = 7; i >= 0; i--) {
      sss[i] = tt % 10;
      tt /= 10;
    }

    for (register int i = 0; i < 4; i++) {
      lsjr.lwz = ls1.lwz + kkk[i];
      if ((ls1.lwz == 3 && lsjr.lwz == 4) || (ls1.lwz == 4 && lsjr.lwz == 3))
        continue;
      if (lsjr.lwz >= 0 && lsjr.lwz <= 7) {
        swap(sss[lsjr.lwz], sss[ls1.lwz]);
        lsjr.ztt = 0;
        for (register int i = 0; i <= 7; i++) {
          lsjr.ztt *= 10;
          lsjr.ztt += sss[i];
        }
        swap(sss[lsjr.lwz], sss[ls1.lwz]);
        if (!vis.count(lsjr.ztt)) {
          lsjr.step = ls1.step + 1;
          vis.insert(lsjr.ztt);
          dl.push(lsjr);
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
    int cs = atoi(bj);
    int lwz = strchr(bj, '0') - bj;
    bfs(cs, lwz);
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