#include <algorithm>
#include <bitset>
#include <functional>
#include <set>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
using namespace std;

// Initial sequence
char zzzt[8] = {0, 1, 2, 3, 4, 5, 6, 7};

// Current sequence
char bj[8];

// Visited sequences
char vis[80000000 / 8];

// Check if sequence was visited
#define ck(x) (vis[(x) >> 3] & (1 << ((x)&7)))

// Mark sequence as visited
#define sb(x) (vis[(x) >> 3] |= (1 << ((x)&7)))

// Mark sequence as not visited
#define cb(x) (vis[(x) >> 3] &= ~(1 << ((x)&7)))

// Node in BFS tree
struct pt {
  int ztt;   // Current sequence
  int lwz;   // Position of '0'
  int step;  // Number of steps taken
};

// Minimum steps to transform sequence to "1234567"
int bs;

// BFS queue
pt dl[1 << 16];
int front = 1, back = 1;

// Whether sequence "1234567" was found
int tt;

// Powers of 10
int ddd[8] = {10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};

// BFS function
void bfs() {
  // Initialize
  tt = 0;
  front = 1;
  back = 1;
  bs = 0;
  memset(vis, 0, sizeof(vis));

  // Convert sequence to integer and mark as visited
  int cs = atoi(bj);
  sb(cs);

  // Add initial node to BFS queue
  pt lsss;
  lsss.ztt = cs;
  lsss.lwz = strchr(bj, '0') - bj;
  lsss.step = 0;
  dl[back] = lsss;
  back++;

  // BFS loop
  while (front < back) {
    // Dequeue node
    pt ls1 = dl[front];
    front++;

    // Check if sequence is "1234567"
    if (ls1.ztt == 1234567) {
      bs = ls1.step;
      tt = 1;
      return;
    }

    // Create next nodes
    pt lsjr;
    int kkk[4] = {-1, 1, -4, 4};
    for (int i = 0; i < 4; i++) {
      lsjr.lwz = ls1.lwz + kkk[i];

      // Invalid move
      if ((ls1.lwz == 3 && lsjr.lwz == 4) || (ls1.lwz == 4 && lsjr.lwz == 3))
        continue;

      // Valid move
      if (lsjr.lwz >= 0 && lsjr.lwz <= 7) {
        int a, b;
        a = ls1.ztt / ddd[ls1.lwz] % 10;
        b = ls1.ztt / ddd[lsjr.lwz] % 10;
        lsjr.ztt = ls1.ztt + (b - a) * ddd[ls1.lwz] + (a - b) * ddd[lsjr.lwz];

        // Check if new sequence was already visited
        if (!ck(lsjr.ztt)) {
          // Mark as visited and enqueue
          lsjr.step = ls1.step + 1;
          sb(lsjr.ztt);
          dl[back] = lsjr;
          back++;
        }
      }
    }
  }
}

// Main function
int main() {
  // Read sequences from standard input
  while (1) {
    if (scanf("%c", &bj[0]) == EOF) {
      return 0;
    }
    scanf("%*c");
    for (int i = 1; i <= 6; i++) {
      scanf("%c%*c", &bj[i]);
    }
    scanf("%c", &bj[7]);

    // Perform BFS
    bfs();

    // Output minimum steps or "-1" if not possible
    if (tt) {
      printf("%d\n", bs);
    } else {
      printf("-1\n");
    }

    // Read until end of line
    while (getchar() != '\n')
      ;
  }

  return 0;
}