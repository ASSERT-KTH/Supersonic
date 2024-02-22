#include <algorithm>
#include <bitset>
#include <cstdint>  // For uint16_t
#include <cstdio>   // For scanf, printf
#include <cstring>  // For memset
#include <vector>

const uint8_t zzzt[8] = {0, 1, 2, 3, 4, 5, 6, 7}; // Change to const

std::bitset<80000000 / 8> vis;  // Change to bitset

bool ck(int x) { return vis[x >> 3] & (1 << (x & 7)); }      // Change to inline function
void sb(int x) { vis[x >> 3] |= (1 << (x & 7)); }           // Change to inline function
void cb(int x) { vis[x >> 3] &= ~(1 << (x & 7)); }          // Change to inline function

struct pt {
  uint16_t ztt; // Change to uint16_t
  uint16_t lwz; // Change to uint16_t
  uint16_t step; // Change to uint16_t
};

std::vector<pt> dl(1 << 16);  // Change to vector
uint16_t front = 1, back = 1; // Change to uint16_t
uint16_t tt;
uint32_t ddd[8] = {10000000, 1000000, 100000, 10000, 1000, 100, 10, 1}; // Change to uint32_t

void bfs() {
  tt = 0;
  front = 1;
  back = 1;
  int bs = 0; // Move bs inside the bfs function
  vis.reset(); // Reset the bitset
  int cs = atoi(bj);
  sb(cs);
  pt lsss;
  lsss.ztt = cs;
  lsss.lwz = strchr(bj, '0') - bj;
  lsss.step = 0;
  dl[back++] = lsss; // Use post-increment operator
  while (front < back) {
    pt ls1 = dl[front++]; // Use post-increment operator
    if (ls1.ztt == 1234567) {
      bs = ls1.step;
      tt = 1;
      break; // Break the loop instead of using return
    }
    pt lsjr;
    int kkk[4] = {-1, 1, -4, 4};
    for (int i = 0; i < 4; i++) {
      lsjr.lwz = ls1.lwz + kkk[i];
      if ((ls1.lwz == 3 && lsjr.lwz == 4) || (ls1.lwz == 4 && lsjr.lwz == 3))
        continue;
      if (lsjr.lwz >= 0 && lsjr.lwz <= 7) {
        uint16_t a, b; // Change to uint16_t
        a = ls1.ztt / ddd[ls1.lwz] % 10;
        b = ls1.ztt / ddd[lsjr.lwz] % 10;
        lsjr.ztt = ls1.ztt + (b - a) * ddd[ls1.lwz] + (a - b) * ddd[lsjr.lwz];
        if (!ck(lsjr.ztt)) {
          lsjr.step = ls1.step + 1;
          sb(lsjr.ztt);
          dl[back++] = lsjr; // Use post-increment operator
        }
      }
    }
  }
  printf("%d\n", tt ? bs : -1); // Move the output outside the loop
}

int main() {
  char bj[8];
  while (scanf("%c", &bj[0]) != EOF) {
    scanf("%*c");
    for (int i = 1; i <= 6; i++) {
      scanf("%c%*c", &bj[i]);
    }
    scanf("%c", &bj[7]);
    bfs();
    scanf("%*[^\n]"); // Skip the rest of the line
  }
  return 0;
}