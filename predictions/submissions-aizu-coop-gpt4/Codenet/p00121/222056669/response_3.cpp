#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAX_NUM = 10000000;
const int MAX_NODE_NUM = 1 << 16;
const int MAX_DIGIT = 8;
const int ddd[MAX_DIGIT] = {10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};

struct pt {
  int ztt;
  int lwz;
  int step;
};

bool vis[MAX_NUM];
queue<pt> dl;

void bfs(char bj[MAX_DIGIT], int& bs, bool& tt) {
  tt = false;
  memset(vis, 0, sizeof(vis));
  int cs = atoi(bj);
  vis[cs] = true;
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
        int a, b;
        a = ls1.ztt / ddd[ls1.lwz] % 10;
        b = ls1.ztt / ddd[lsjr.lwz] % 10;
        lsjr.ztt = ls1.ztt + (b - a) * ddd[ls1.lwz] + (a - b) * ddd[lsjr.lwz];
        if (!vis[lsjr.ztt]) {
          lsjr.step = ls1.step + 1;
          vis[lsjr.ztt] = true;
          dl.push(lsjr);
        }
      }
    }
  }
}

int main() {
  char bj[MAX_DIGIT];
  int bs;
  bool tt;
  while (scanf("%c", &bj[0]) != EOF) {
    scanf("%*c");
    for (int i = 1; i <= 6; i++) {
      scanf("%c%*c", &bj[i]);
    }
    scanf("%c", &bj[7]);
    bfs(bj, bs, tt);
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