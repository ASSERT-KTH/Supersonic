#include <iostream>

constexpr int MAX = 2000000;
constexpr int INFTY = (1 << 30);

int H, A[MAX + 1];

void maxHeap(int i) {
  int l, r, large;
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
  if (large != i) {
    std::swap(A[large], A[i]);
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
    std::swap(A[i], A[i / 2]);
    i = i / 2;
  }
}

void insert(int key) {
  increasekey(++H, key);
}

int main() {
  int key;
  char com[10];
  while (true) {
    std::cin >> com;
    if (com[0] == 'e' && com[1] == 'n')
      break;
    if (com[0] == 'i') {
      std::cin >> key;
      insert(key);
    } else {
      std::cout << extract() << std::endl;
    }
  }
  return 0;
}