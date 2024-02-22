#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

#define MAX 2000000
#define INFTY (1 << 30)

void maxHeap(int A[], int H, int i) {
  int l, r, large;
  while (1) {
    l = 2 * i;
    r = 2 * i + 1;
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
    A[i] ^= A[large] ^= A[i] ^= A[large];
    i = large;
  }
}

int extract(int A[], int& H) {
  int maxv;
  if (H < 1)
    return -INFTY;
  maxv = A[1];
  A[1] = A[H--];
  maxHeap(A, H, 1);
  return maxv;
}

void increasekey(int A[], int i, int key) {
  if (key <= A[i])
    return;
  A[i] = key;
  while (i > 1 && A[i / 2] < A[i]) {
    A[i] ^= A[i / 2] ^= A[i] ^= A[i / 2];
    i = i / 2;
  }
}

int insert(int A[], int& H, int key) {
  H++;
  A[H] = -INFTY;
  increasekey(A, H, key);
}

int main() {
  int H = 0;
  int A[MAX + 1];
  char buffer[20];
  char com[10];
  int key;

  while (1) {
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%s", com);
    if (com[0] == 'e' && com[1] == 'n')
      break;
    if (com[0] == 'i') {
      sscanf(buffer, "%*s %d", &key);
      insert(A, H, key);
    } else {
      std::cout << extract(A, H) << std::endl;
    }
  }

  return 0;
}