#include <bitset>
#include <stdio.h>
using namespace std;

bitset<10000000> vis;
struct pt {
  char ztt[8];
  int lwz;
  int step;
};
int bs;
pt dl[1 << 16];
int front = 1, back = 1;
bool tt;
void bfs(char bj[8], int zeroPos) {
  front = 1;
  back = 1;
  tt = false;
  vis.reset();
  pt lsss;
  for(int i=0; i<8; i++) {
    lsss.ztt[i] = bj[i];
  }
  lsss.lwz = zeroPos;
  lsss.step = 0;
  dl[back] = lsss;
  back++;
  while (front < back) {
    pt ls1 = dl[front];
    front++;
    if (memcmp(ls1.ztt, "1234567\0", 8) == 0) {
      bs = ls1.step;
      tt = true;
      return;
    }
    pt lsjr;
    int kkk[4] = {-1, 1, -4, 4};
    for (int i = 0; i < 4; i++) {
      lsjr.lwz = ls1.lwz + kkk[i];
      if ((ls1.lwz == 3 && lsjr.lwz == 4) || (ls1.lwz == 4 && lsjr.lwz == 3))
        continue;
      if (lsjr.lwz >= 0 && lsjr.lwz <= 7) {
        for(int i=0; i<8; i++) {
          lsjr.ztt[i] = ls1.ztt[i];
        }
        swap(lsjr.ztt[lsjr.lwz], lsjr.ztt[ls1.lwz]);
        if (!vis[atoi(lsjr.ztt)]) {
          lsjr.step = ls1.step + 1;
          vis[atoi(lsjr.ztt)] = 1;
          dl[back] = lsjr;
          back++;
        }
      }
    }
  }
}
int main() {
  char zzzt[8] = {0, 1, 2, 3, 4, 5, 6, 7};
  char bj[8];
  int zeroPos;
  while (1) {
    if (scanf("%c", &bj[0]) == EOF) {
      return 0;
    }
    if(bj[0] == '0') zeroPos = 0;
    scanf("%*c");
    for (int i = 1; i <= 6; i++) {
      scanf("%c%*c", &bj[i]);
      if(bj[i] == '0') zeroPos = i;
    }
    scanf("%c", &bj[7]);
    if(bj[7] == '0') zeroPos = 7;
    bfs(bj, zeroPos);
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