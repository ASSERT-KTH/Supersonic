#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define MAX 2000000
#define INFTY (1 << 30)
int H, A[MAX + 1];
void maxHeap(int i) {
  int large = i;
  int left = 2 * i;
  int right = 2 * i + 1;

  if (left <= H && A[left] > A[large]) {
    large = left;
  }
  if (right <= H && A[right] > A[large]) {
    large = right;
  }
  if (large != i) {
    swap(A[large], A[i]);
    maxHeap(large);
  }
}
int extract() {
  int maxv;
  if (H < 1)
    return -INFTY;
  maxv = A[1];
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
int insert(int key) {
  H++;
  A[H] = -INFTY;
  increasekey(H, key);
}
int main() {
  int key;
  char com[10];
  while (1) {
    cin >> com;
    if (com[0] == 'e' && com[1] == 'n')
      break;
    if (com[0] == 'i') {
      cin >> key;
      insert(key);
    } else {
      cout << extract() << endl;
    }
  }
  return 0;
}