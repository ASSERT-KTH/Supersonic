#include <iostream>
using namespace std;

#define MAX 2000000

int A[MAX + 1];
int H = 0;

void maxHeap(int i) {
  int large = i;
  while (true) {
    int l = 2 * i;
    int r = 2 * i + 1;
    if (l <= H && A[l] > A[i]) {
      large = l;
    }
    if (r <= H && A[r] > A[large]) {
      large = r;
    }
    if (large == i) {
      break;
    }
    swap(A[large], A[i]);
    i = large;
  }
}

int extract() {
  if (H < 1) {
    return -INFTY;
  }
  int maxv = A[1];
  A[1] = A[H--];
  maxHeap(1);
  return maxv;
}

void increasekey(int i, int key) {
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
  while (true) {
    cin >> com;
    if (com[0] == 'e' && com[1] == 'n') {
      break;
    }
    if (com[0] == 'i') {
      cin >> key;
      insert(key);
    } else {
      cout << extract() << endl;
    }
  }
  return 0;
}