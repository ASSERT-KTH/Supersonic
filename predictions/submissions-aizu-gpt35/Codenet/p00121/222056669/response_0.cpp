#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
char zzzt[8] = {0, 1, 2, 3, 4, 5, 6, 7};
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
int ddd[8] = {10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};
void bfs() {
  tt = 0;
  front = 1;
  back = 1;
  bs = 0;
  vis.reset();
  int cs = atoi(bj);
  vis[cs] = true;
  pt lsss{cs, strchr(bj, '0') - bj, 0};
  dl[back++] = lsss;
  while (front < back) {
    pt ls1 = dl[front++];
    if (ls1.ztt == 1234567) {
      bs = ls1.step;
      tt = 1;
      return;
    }
    int kkk[4] = {-1, 1, -4, 4};
    for (int i = 0; i < 4; i++) {
      pt lsjr;
      lsjr.lwz = ls1.lwz + kkk[i];
      if ((ls1.lwz == 3 && lsjr.lwz == 4) || (ls1.lwz == 4 && lsjr.lwz == 3))
        continue;
      if (lsjr.lwz >= 0 && lsjr.lwz <= 7) {
        int a, b;
        a = ls1.ztt / ddd[ls1.lwz] % 10;
        b = ls1.ztt / ddd[lsjr.lwz] % 10;
        lsjr.ztt = ls1.ztt + (b - a) * ddd[ls1.lwz] + (a - b) * ddd[lsjr.lwz];
        if (!vis[lsjr.ztt]) {
          lsjr.step = ls1.step + 1;
          vis[lsjr.ztt] = true;
          dl[back++] = lsjr;
        }
      }
    }
  }
}
int main() {
  while (~scanf("%s", bj)) {
    for (int i = 1; i <= 6; i++) {
      scanf("%s", bj + i);
    }
    bfs();
    printf("%d\n", tt ? bs : -1);
  }
  return 0;
}