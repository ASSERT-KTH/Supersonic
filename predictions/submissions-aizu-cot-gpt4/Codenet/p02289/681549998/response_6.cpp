#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define MAX 2000000
#define INFTY (1 << 30)
int H, A[MAX + 1];
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
  int maxv = max(A[1], -INFTY);
  A[1] = A[H--];
  maxHeap(1);
  return maxv;
}
void increasekey(int i, int key) {
  if (key < A[i])
    return;
  A[i] = key;
  for (; i > 1 && A[i / 2] < A[i]; i /= 2)
    swap(A[i], A[i / 2]);
}
int insert(int key) {
  H++;
  A[H] = -INFTY;
  increasekey(H, key);
}
int main() {
  int key;
  char com[10];
  do {
    cin >> com;
    if (com[0] == 'i') {
      cin >> key;
      insert(key);
    } else if (com[0] != 'e') {
      cout << extract() << endl;
    }
  } while (com[0] != 'e' || com[1] != 'n');
  return 0;
}