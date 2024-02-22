#include <stdio.h>
#include <string.h>
#include <bitset>

const int MAX_STATES = 80000000;
const int MAX_MOVES = 16;
const int MAX_DIGITS = 8;

int zzzt[MAX_DIGITS] = {0, 1, 2, 3, 4, 5, 6, 7};
int bj[MAX_DIGITS];

std::bitset<MAX_STATES> vis;

struct pt {
  int ztt;
  int lwz;
  int step;
};

pt dl[MAX_MOVES];
int bs;

void bfs() {
  int front = 1;
  int back = 1;
  int tt = 0;
  int bs = 0;

  vis.reset();

  int cs = 0;
  for (int i = 0; i < MAX_DIGITS; i++) {
    cs *= 10;
    cs += bj[i];
  }

  vis[cs] = 1;

  pt lsss;
  lsss.ztt = cs;
  lsss.lwz = std::find(bj, bj + MAX_DIGITS, 0) - bj;
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

    for (int i = 0; i < MAX_DIGITS; i++) {
      int sss[MAX_DIGITS];
      memcpy(sss, &ls1.ztt, sizeof(sss));

      lsjr.lwz = ls1.lwz + kkk[i];
      if ((ls1.lwz == 3 && lsjr.lwz == 4) || (ls1.lwz == 4 && lsjr.lwz == 3)) {
        continue;
      }

      if (lsjr.lwz >= 0 && lsjr.lwz <= 7) {
        std::swap(sss[lsjr.lwz], sss[ls1.lwz]);

        lsjr.ztt = 0;
        for (int j = 0; j < MAX_DIGITS; j++) {
          lsjr.ztt *= 10;
          lsjr.ztt += sss[j];
        }

        std::swap(sss[lsjr.lwz], sss[ls1.lwz]);

        if (!vis[lsjr.ztt]) {
          lsjr.step = ls1.step + 1;
          vis[lsjr.ztt] = 1;
          dl[back] = lsjr;
          back++;
        }
      }
    }
  }

  if (tt) {
    bs = ls1.step;
    printf("%d\n", bs);
  } else {
    printf("-1\n");
  }
}

int main() {
  do {
    for (int i = 0; i < MAX_DIGITS; i++) {
      scanf("%d%*c", &bj[i]);
    }

    bfs();

    while (getchar() != '\n')
      ;
  } while (!feof(stdin));

  return 0;
}