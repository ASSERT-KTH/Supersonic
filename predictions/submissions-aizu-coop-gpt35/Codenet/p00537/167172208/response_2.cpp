#include <iostream>
using namespace std;

struct SegmentTree {
  int *seg, *add;
  int sz;
  
  SegmentTree(int n) {
    sz = 1;
    while (sz < n)
      sz *= 2;
    seg = new int[sz * 2 + 1];
    add = new int[sz * 2 + 1];
    memset(seg, 0, sizeof(int) * (sz * 2 + 1));
    memset(add, 0, sizeof(int) * (sz * 2 + 1));
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
  scanf("%d %d", &N, &M);
  SegmentTree segtree(N);
  for (int i = 0; i < M; i++) {
    scanf("%d", &P[i]);
    --P[i];
  }
  for (int i = 1; i < M; i++) {
    int u = min(P[i - 1], P[i]), v = max(P[i - 1], P[i]);
    segtree.Add(u, v, 1);
  }
  long long ret = 0;
  int used = segtree.Query(0, 1);
  for (int i = 0; i < N - 1; i++) {
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    ret += min((long long)used * A, (long long)C + used * B);
    used += segtree.Query(i + 1, i + 2);
  }
  cout << ret << endl;

  delete[] segtree.seg;
  delete[] segtree.add;
  return 0;
}