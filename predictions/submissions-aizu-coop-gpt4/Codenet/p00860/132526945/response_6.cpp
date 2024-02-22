#include <cctype>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

unsigned short vis[1 << 24];
char c[16][20];
bool wall[256];
int tm0;

inline bool check(int u, int v) {
  for (int i = 0; i < 24; i += 8) {
    int p1 = v >> i & 255;
    if (p1) {
      int j = i == 16 ? 0 : i + 8;
      if (wall[p1]) {
        return false;
      }
      int p2 = (v >> j % 24) & 255; // Store the result of the operation
      int u1 = (u >> j % 24 & 255); // Store the result of the operation
      int u2 = (u >> i % 24 & 255); // Store the result of the operation
      if (p1 == p2 || p1 == u1 && p2 == u2) {
        return false;
      }
    }
  }
  return true;
}

// Rest of the code remains the same