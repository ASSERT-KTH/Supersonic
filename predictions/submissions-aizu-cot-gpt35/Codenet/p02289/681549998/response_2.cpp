#include <iostream>

#define MAX 2000000

int H, A[MAX + 1];

void maxHeap(int i) {
  int large = i;
  while (true) {
    int l = 2 * i;
    int r = 2 * i + 1;
    if (l <= H && A[l] > A[large]) {
      large = l;
    }
    if (r <= H && A[r] > A[large]) {
      large = r;
    }
    if (large == i) {
      break;
    }
    std::swap(A[large], A[i]);
    i = large;
  }
}

int extract() {
  if (H < 1) {
    return -1;
  }
  int maxv = A[1];
  A[1] = A[H--];
  maxHeap(1);
  return maxv;
}

void increasekey(int i, int key) {
  A[i] = key;
  while (i > 1 && A[i / 2] < A[i]) {
    std::swap(A[i], A[i / 2]);
    i = i / 2;
  }
}

void insert(int key) {
  H++;
  increasekey(H, key);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  char com[10];
  while (true) {
    std::cin >> com;
    if (com[0] == 'e' && com[1] == 'n') {
      break;
    }
    if (com[0] == 'i') {
      int key;
      std::cin >> key;
      insert(key);
    } else {
      std::cout << extract() << '\n';
    }
  }
  return 0;
}