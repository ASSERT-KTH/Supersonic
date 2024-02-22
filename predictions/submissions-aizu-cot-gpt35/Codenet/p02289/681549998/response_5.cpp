#include <iostream>
#include <climits>

const int MAX = 2000000;
const int INFTY = INT_MAX;

int H, A[MAX + 1];

void maxHeap(int& i) {
  int& l = 2 * i;
  int& r = 2 * i + 1;
  int& large = (l <= H && A[l] > A[i]) ? l : i;
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
  if (key <= A[i])
    return;
  A[i] = key;
  while (i > 1 && A[i / 2] < A[i]) {
    std::swap(A[i], A[i / 2]);
    i = i / 2;
  }
}

void insert(int key) {
  A[++H] = key;
  increasekey(H, key);
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int key;
  char com[10];
  while (1) {
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