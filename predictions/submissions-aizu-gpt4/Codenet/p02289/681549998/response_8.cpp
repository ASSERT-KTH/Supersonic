#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define MAX 2000000
#define INFTY (1 << 30)
int H = 0, A[MAX + 1];
void maxHeap(int i) {
  int l = 2 * i;
  int r = 2 * i + 1;
  int large = (l <= H && A[l] > A[i]) ? l : i;
  large = (r <= H && A[r] > A[large]) ? r : large;
  if (large != i) {
    swap(A[large], A[i]);
    maxHeap(large);
  }
}
int extract() {
  if (H < 1)
    return -INFTY;
  int maxv = A[1];
  A[1] = A[H--];
  maxHeap(1);
  return maxv;
}
void increasekey(int i, int key) {
  if (key < A[i])
    return;
  A[i] = key;
  while (i > 1 && A[i / 2] < A[i]) {
    swap(A[i], A[i / 2]);
    i = i / 2;
  }
}
void insert(int key) {
  A[++H] = -INFTY;
  increasekey(H, key);
}
int main() {
  string com;
  while (cin >> com) {
    if (com == "end")
      break;
    if (com == "insert") {
      int key;
      cin >> key;
      insert(key);
    } else {
      cout << extract() << '\n';
    }
  }
  return 0;
}