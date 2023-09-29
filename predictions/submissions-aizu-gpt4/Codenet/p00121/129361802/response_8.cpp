#include <algorithm>
#include <bitset>
#include <functional>
#include <set>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
constexpr int MAX_SIZE = 1000000;
char zzzt[8] = {0, 1, 2, 3, 4, 5, 6, 7};
char bj[8];
bitset<MAX_SIZE> vis;
struct pt {
  int ztt;
  int lwz;
  int step;
};
int bs;
vector<pt> dl(MAX_SIZE);
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
          lsjr.ztt = lsjr.ztt * 10 + sss[i];
        }
        swap(sss[lsjr.lwz], sss[ls1.lwz]);
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
    for (int i = 1; i <= 6; i++) {
      scanf("%c%*c", &bj[i]);
    }
    scanf("%c", &bj[7]);
    bfs();
    printf(tt ? "%d\n" : "-1\n", bs);
    while (getchar() != '\n')
      ;
  }
  return 0;
}