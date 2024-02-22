#include <stdio.h>
#include <string.h>

char bj[8];
char vis[80000000 / 8];
int dl[1 << 16];
int front = 1, back = 1;
int bs;
int tt;

#define ck(x) (vis[(x) >> 3] & (1 << ((x)&7)))
#define sb(x) (vis[(x) >> 3] |= (1 << ((x)&7)))
#define cb(x) (vis[(x) >> 3] &= ~(1 << ((x)&7)))

struct pt {
  int ztt;
  int lwz;
  int step;
};

void bfs() {
  tt = 0;
  front = 1;
  back = 1;
  bs = 0;
  memset(vis, 0, sizeof(vis));
  int cs = atoi(bj);
  sb(cs);
  dl[back++] = {cs, strchr(bj, '0') - bj, 0};

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
        int a = ls1.ztt / 10000000 % 10;
        int b = ls1.ztt / 1000000 % 10;
        lsjr.ztt = ls1.ztt + (b - a) * 10000000 + (a - b) * 1000000;
        
        if (!ck(lsjr.ztt)) {
          lsjr.step = ls1.step + 1;
          sb(lsjr.ztt);
          dl[back++] = lsjr;
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