#include <iostream>
#include <cstdio>

struct SegmentTree {
  int* seg;
  int* add;
  int sz;

  SegmentTree(int n) {
    sz = 1;
    while (sz < n)
      sz *= 2;
    seg = new int[sz * 2 + 1];
    add = new int[sz * 2 + 1];
    for (int i = 0; i < sz * 2 + 1; i++) {
      seg[i] = 0;
      add[i] = 0;
    }
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
    while (a < b) {
      if (a % 2 == 1) {
        res += seg[a] + add[a];
        a++;
      }
      if (b % 2 == 1) {
        b--;
        res += seg[b] + add[b];
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
  for (int i = 0; i < N - 1; i++) {
    long long used = segtree.Query(i, i + 1);
    int A, B, C;
    std::scanf("%d %d %d", &A, &B, &C);
    ret += std::min(used * A, C + used * B);
  }
  std::cout << ret << std::endl;

  // Clean up dynamically allocated memory
  delete[] segtree.seg;
  delete[] segtree.add;
}