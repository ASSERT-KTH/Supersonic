#include <algorithm>
#include <iostream>
using namespace std;
#define MAX 2000000
#define INFTY (1 << 30)
int H, A[MAX + 1];

void maxHeap(int i) {
  int l = 2 * i;
  int r = 2 * i + 1;
  int large = (l <= H && A[l] > A[i]) ? l : i;
  if (r <= H && A[r] > A[large]) {
    large = r;
  }
  if (large != i) {
    swap(A[large], A[i]);
    maxHeap(large);
  }
}

void insert(int key) {
  H++;
  A[H] = -INFTY;
  if (key < A[H])
    return;
  A[H] = key;
  int i = H;
  while (i > 1 && A[i / 2] < A[i]) {
    swap(A[i], A[i / 2]);
    i = i / 2;
  }
}

int main() {
  int key;
  string com;
  while (1) {
    cin >> com;
    if (com == "end")
      break;
    if (com[0] == 'i') {
      cin >> key;
      insert(key);
    } else {
      if (H < 1)
        cout << -INFTY << "\n";
      else {
        int maxv = A[1];
        A[1] = A[H--];
        maxHeap(1);
        cout << maxv << "\n";
      }
    }
  }
  return 0;
}