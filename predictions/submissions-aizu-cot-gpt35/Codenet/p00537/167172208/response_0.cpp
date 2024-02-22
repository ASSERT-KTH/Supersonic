#include <vector>
#include <iostream>
#include <cstdio>

struct SegmentTree {
  std::vector<int> seg, add;
  int sz;
  
  SegmentTree(int n) : sz(1) {
    while (sz < n)
      sz *= 2;
    seg.resize(sz * 2 + 1, 0);
    add.resize(sz * 2 + 1, 0);
  }
  
  void Add(int a, int b, int x) {
    a += sz;
    b += sz;
    while (a < b) {
      if (a % 2 == 1) {
        add[a] += x;
        seg[a] += x;
        a++;
      }
      if (b % 2 == 1) {
        b--;
        add[b] += x;
        seg[b] += x;
      }
      a /= 2;
      b /= 2;
    }
  }
  
  int Query(int a, int b) {
    a += sz;
    b += sz;
    int res = 0;
    while (a <= b) {
      if (a % 2 == 1) {
        res += seg[a] + add[a];
        a++;
      }
      if (b % 2 == 0) {
        res += seg[b] + add[b];
        b--;
      }
      a /= 2;
      b /= 2;
    }
    return res;
  }
};

int main() {
  int N, M, P[100000];
  std::scanf("%d %d", &N, &M);
  SegmentTree segtree(N);
  for (int i = 0; i < M; i++) {
    std::scanf("%d", &P[i]);
    --P[i];
  }
  for (int i = 1; i < M; i++) {
    int u = std::min(P[i - 1], P[i]);
    int v = std::max(P[i - 1], P[i]);
    segtree.Add(u, v, 1);
  }
  long long ret = 0;
  int used, A, B, C;
  for (int i = 0; i < N - 1; i++) {
    used = segtree.Query(i, i + 1);
    std::scanf("%d %d %d", &A, &B, &C);
    ret += std::min(static_cast<long long>(used) * A, C + static_cast<long long>(used) * B);
  }
  std::cout << ret << std::endl;
}