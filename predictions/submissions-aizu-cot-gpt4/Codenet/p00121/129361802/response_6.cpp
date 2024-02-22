#include <algorithm>
#include <bitset>
#include <functional>
#include <queue>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct pt {
  int ztt;
  int lwz;
  int step;
};

char bj[8];
bitset<1234567> vis;
int bs;
queue<pt> dl;
int tt;

void bfs() {
  tt = 0;
  bs = 0;
  vis.reset();
  int cs = atoi(bj);
  vis[cs] = 1;
  pt lsss;
  lsss.ztt = cs;
  lsss.lwz = strchr(bj, '0') - bj;
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
    for (int i = 7; i >= 0; i--) {
      sss[i] = tt % 10;
      tt /= 10;
    }
    
    for (int i = 0; i < 4; i++) {
      lsjr.lwz = ls1.lwz + kkk[i];
      if ((ls1.lwz == 3 && lsjr.lwz == 4) || (ls1.lwz == 4 && lsjr.lwz == 3))
        continue;
      if (lsjr.lwz >= 0 && lsjr.lwz <= 7) {
        swap(sss[lsjr.lwz], sss[ls1.lwz]);
        lsjr.ztt = 0;
        for (int i = 0; i <= 7; i++) {
          lsjr.ztt *= 10;
          lsjr.ztt += sss[i];
        }
        swap(sss[lsjr.lwz], sss[ls1.lwz]);
        if (!vis[lsjr.ztt]) {
          lsjr.step = ls1.step + 1;
          vis[lsjr.ztt] = 1;
          dl.push(lsjr);
        }
      }
    }
  }
}

int main() {
  while (1) {
    if (!(cin >> bj[0])) {
      return 0;
    }
    for (int i = 1; i <= 6; i++) {
      cin >> bj[i];
    }
    cin >> bj[7];
    bfs();
    if (tt) {
      cout << bs << endl;
    } else {
      cout << "-1" << endl;
    }
    cin.ignore();
  }
  return 0;
}