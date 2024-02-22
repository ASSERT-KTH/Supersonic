#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define MAX 2000000
#define INFTY (1 << 30)

int H, A[MAX + 1];

void maxHeap() {
  int i = 1;
  while (true) {
    int l = 2 * i;
    int r = 2 * i + 1;
    int large = i;
    if (l <= H && A[l] > A[i]) {
      large = l;
    }
    if (r <= H && A[r] > A[large]) {
      large = r;
    }
    if (large != i) {
      int temp = A[large];
      A[large] = A[i];
      A[i] = temp;
      i = large;
    } else {
      break;
    }
  }
}

int extract() {
  int maxv;
  if (H < 1)
    return -INFTY;
  maxv = A[1];
  A[1] = A[H--];
  maxHeap();
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
  char com[10];
  while (true) {
    scanf("%s", com);
    if (com[0] == 'e' && com[1] == 'n')
      break;
    if (com[0] == 'i') {
      scanf("%d", &key);
      insert(key);
    } else {
      printf("%d\n", extract());
    }
  }
  return 0;
}