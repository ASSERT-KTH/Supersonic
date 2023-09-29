#include <algorithm>
#include <bitset>
#include <functional>
#include <set>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
char zzzt[8] = {0, 1, 2, 3, 4, 5, 6, 7};
char bj[8];
char vis[40000000 / 8];
#define ck(x) (vis[(x) >> 3] & (1 << ((x)&7)))
#define sb(x) (vis[(x) >> 3] |= (1 << ((x)&7)))
#define cb(x) (vis[(x) >> 3] &= ~(1 << ((x)&7)))
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
  memset(vis, 0, sizeof(vis));
  int cs = atoi(bj);
  sb(cs);
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
