#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define MAX 2000000
#define INFTY (1 << 30)
int H, A[MAX + 1];
inline void maxHeap(int i) {
  int l, r, large;
  while (true) {
    l = (i << 1);
    r = (i << 1) + 1;
    large = i;
    if (l <= H && A[l] > A[large]) {
      large = l;
    }
    if (r <= H && A[r] > A[large]) {
      large = r;
    }
    if (large != i) {
      swap(A[large], A[i]);
      i = large;
    } else {
      break;
    }
  }
}
inline int extract() {
  int maxv = A[1];
  A[1] = A[H--];
  maxHeap(1);
  return maxv;
}
inline void increasekey(int i, int key) {
  A[i] = key;
  while (i > 1 && A[i >> 1] < A[i]) {
    swap(A[i], A[i >> 1]);
    i >>= 1;
  }
}
inline void insert(int key) {
  A[++H] = -INFTY;
  increasekey(H, key);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int key;
  char com[10];
  while (true) {
    cin >> com;
    if (com[0] == 'e') {
      if (com[1] == 'n') {
        break;
      }
    }
    if (com[0] == 'i') {
      cin >> key;
      insert(key);
    } else {
      cout << extract() << '\n';
    }
  }
  return 0;
}