#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define MAX 2000000
#define INFTY (1 << 30)
int H, A[MAX + 1];

void maxHeap(int i) {
  int large;
  while (true) {
    int l = 2 * i;
    int r = 2 * i + 1;
    if (l <= H && A[l] > A[i]) {
      large = l;
    } else {
      large = i;
    }
    if (r <= H && A[r] > A[large]) {
      large = r;
    }
    if (large == i) {
      break;
    }
    int temp = A[i];
    A[i] = A[large];
    A[large] = temp;
    i = large;
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
    int temp = A[i];
    A[i] = A[i / 2];
    A[i / 2] = temp;
    i = i / 2;
  }
}

void insert(int key) {
  H++;
  A[H] = -INFTY;
  increasekey(H, key);
}

int main() {
  int key;
  string com;
  while (1) {
    cin >> com;
    if (com == "end")
      break;
    if (com == "insert") {
      cin >> key;
      insert(key);
    } else {
      cout << extract() << endl;
    }
  }
  return 0;
}