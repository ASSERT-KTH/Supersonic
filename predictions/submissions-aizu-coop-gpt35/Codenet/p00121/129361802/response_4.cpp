#include <stdio.h>
#include <string.h>
#include <vector>

struct pt {
  int ztt;
  int lwz;
  int step;
};

void bfs(const char* bj) {
  std::vector<pt> dl(1 << 16);
  int front = 1, back = 1;
  int tt = 0;
  int bs = 0;
  std::vector<bool> vis(10000000, false);

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
      break;
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
        char t = sss[lsjr.lwz];
        sss[lsjr.lwz] = sss[ls1.lwz];
        sss[ls1.lwz] = t;
        lsjr.ztt = 0;
        for (int i = 0; i <= 7; i++) {
          lsjr.ztt *= 10;
          lsjr.ztt += sss[i];
        }
        t = sss[lsjr.lwz];
        sss[lsjr.lwz] = sss[ls1.lwz];
        sss[ls1.lwz] = t;
        if (!vis[lsjr.ztt]) {
          lsjr.step = ls1.step + 1;
          vis[lsjr.ztt] = true;
          dl[back] = lsjr;
          back++;
        }
      }
    }
  }

  if (tt) {
    printf("%d\n", bs);
  } else {
    printf("-1\n");
  }
}

int main() {
  while (1) {
    char bj[8];
    if (scanf("%s", bj) == EOF) {
      return 0;
    }
    bfs(bj);
    while (getchar() != '\n')
      ;
  }
  return 0;
}