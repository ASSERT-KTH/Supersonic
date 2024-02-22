#include <algorithm>
#include <bitset>
#include <functional>
#include <unordered_set>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
constexpr char zzzt[8] = {0, 1, 2, 3, 4, 5, 6, 7};
char bj[8];
unordered_set<int> vis;
#define ck(x) (vis.find((x)) != vis.end())
#define sb(x) vis.insert(x)
#define cb(x) vis.erase(x)
struct pt {
  int ztt;
  int lwz;
  int step;
};
int bs;
pt dl[1 << 16];
int front = 1, back = 1;
int tt;
constexpr int ddd[8] = {10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};
void bfs() {
  tt = 0;
  front = 1;
  back = 1;
  bs = 0;
  vis.clear();
  const int cs = atoi(bj);
  sb(cs);
  pt lsss;
  lsss.ztt = cs;
  lsss.lwz = strchr(bj, '0') - bj;
  lsss.step = 0;
  dl[back] = lsss;
  ++back;
  while (front < back) {
    const pt ls1 = dl[front];
    ++front;
    if (ls1.ztt == 1234567) {
      bs = ls1.step;
      tt = 1;
      return;
    }
    pt lsjr;
    const int kkk[4] = {-1, 1, -4, 4};
    for (int i = 0; i < 4; ++i) {
      lsjr.lwz = ls1.lwz + kkk[i];
      if ((ls1.lwz == 3 && lsjr.lwz == 4) || (ls1.lwz == 4 && lsjr.lwz == 3))
        continue;
      if (lsjr.lwz >= 0 && lsjr.lwz <= 7) {
        const int a = ls1.ztt / ddd[ls1.lwz] % 10;
        const int b = ls1.ztt / ddd[lsjr.lwz] % 10;
        lsjr.ztt = ls1.ztt + (b - a) * ddd[ls1.lwz] + (a - b) * ddd[lsjr.lwz];
        if (!ck(lsjr.ztt)) {
          lsjr.step = ls1.step + 1;
          sb(lsjr.ztt);
          dl[back] = lsjr;
          ++back;
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
    for (int i = 1; i <= 6; ++i) {
      cin >> bj[i];
    }
    cin >> bj[7];
    bfs();
    if (tt) {
      cout << bs << "\n";
    } else {
      cout << "-1\n";
    }
    while (getchar() != '\n')
      ;
  }
  return 0;
}