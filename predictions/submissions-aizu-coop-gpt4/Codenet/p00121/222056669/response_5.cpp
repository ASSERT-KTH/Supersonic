#include <algorithm>
#include <bitset>
#include <functional>
#include <set>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
using namespace std;

bool vis[100000000];
struct pt {
  int ztt[8];
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
  memset(vis, 0, sizeof(vis));
  int cs = 0;
  for(int i = 0; i < 8; ++i) {
    cs = cs * 10 + bj[i] - '0';
  }
  vis[cs] = true;
  pt lsss;
  for(int i = 0; i < 8; ++i) {
    lsss.ztt[i] = bj[i] - '0';
  }
  lsss.lwz = strchr(bj, '0') - bj;
  lsss.step = 0;
  dl[back] = lsss;
  back++;
  while (front < back) {
    pt ls1 = dl[front];
    front++;
    cs = 0;
    for(int i = 0; i < 8; ++i) {
      cs = cs * 10 + ls1.ztt[i];
    }
    if (cs == 12345678) {
      bs = ls1.step;
      tt = 1;
      return;
    }
    pt lsjr;
    int kkk[4] = {-1, 1, -4, 4};
    for (int i = 0; i < 4; i++) {
      lsjr = ls1;
      lsjr.lwz += kkk[i];
      if ((ls1.lwz == 3 && lsjr.lwz == 4) || (ls1.lwz == 4 && lsjr.lwz == 3))
        continue;
      if (lsjr.lwz >= 0 && lsjr.lwz <= 7) {
        swap(lsjr.ztt[ls1.lwz], lsjr.ztt[lsjr.lwz]);
        cs = 0;
        for(int i = 0; i < 8; ++i) {
          cs = cs * 10 + lsjr.ztt[i];
        }
        if (!vis[cs]) {
          lsjr.step++;
          vis[cs] = true;
          dl[back] = lsjr;
          back++;
        }
      }
    }
  }
}
// rest of the code remains the same as the original