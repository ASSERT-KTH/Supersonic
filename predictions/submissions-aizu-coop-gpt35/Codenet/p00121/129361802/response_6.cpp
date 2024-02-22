#include <algorithm>
#include <bitset>
#include <cstdio>
#include <vector>
using namespace std;

bitset<9> zzzt;
bitset<9> bj;
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
  int cs = static_cast<int>(bj.to_ulong());
  vis[cs] = 1;
  pt lsss;
  lsss.ztt = cs;
  lsss.lwz = (bj.to_string().find('0')) - bj.to_string().begin();
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
    vector<int> validMoves = {-1, 1, -4, 4};
    string sss = bj.to_string();
    int tt = ls1.ztt;
    for (int i = 7; i >= 0; i--) {
      sss[i] = (tt / ddd[i]) % 10;
    }
    for (int i = 0; i < 4; i++) {
      lsjr.lwz = ls1.lwz + validMoves[i];
      if ((ls1.lwz == 3 && lsjr.lwz == 4) || (ls1.lwz == 4 && lsjr.lwz == 3))
        continue;
      if (lsjr.lwz >= 0 && lsjr.lwz <= 7) {
        int t = sss[lsjr.lwz];
        sss[lsjr.lwz] = sss[ls1.lwz];
        sss[ls1.lwz] = t;
        lsjr.ztt = 0;
        for (int i = 0; i <= 7; i++) {
          lsjr.ztt += sss[i] * ddd[i];
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
    bj[0] = getchar_unlocked();
    getchar_unlocked();
    for (int i = 1; i <= 6; i++) {
      bj[i] = getchar_unlocked();
      getchar_unlocked();
    }
    bj[7] = getchar_unlocked();
    bfs();
    if (tt) {
      printf("%d\n", bs);
    } else {
      printf("-1\n");
    }
    while (getchar_unlocked() != '\n')
      ;
  }
  return 0;
}