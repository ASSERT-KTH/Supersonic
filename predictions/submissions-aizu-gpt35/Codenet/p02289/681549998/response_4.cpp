#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX 2000000
#define INFTY (1 << 30)

int H, A[MAX + 1];

inline void maxHeap(int i) {
  int l = 2 * i, r = 2 * i + 1, large = i;
  if (l <= H && A[l] > A[i]) large = l;
  if (r <= H && A[r] > A[large]) large = r;
  if (large != i) {
    swap(A[large], A[i]);
    maxHeap(large);
  }
}

inline int extract() {
  int maxv;
  if (H < 1) return -INFTY;
  maxv = A[1];
  A[1] = A[H--];
  maxHeap(1);
  return maxv;
}

inline void increasekey(int i, int key) {
  while (i > 1 && A[i / 2] < key) {
    A[i] = A[i / 2];
    i /= 2;
  }
  A[i] = key;
}

inline int insert(int key) {
  A[++H] = -INFTY;
  increasekey(H, key);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int key;
  char com[10];
  while (1) {
    cin >> com;
    if (com[0] == 'e' && com[1] == 'n') break;
    if (com[0] == 'i') {
      cin >> key;
      insert(key);
    } else {
      cout << extract() << endl;
    }
  }
  return 0;
}