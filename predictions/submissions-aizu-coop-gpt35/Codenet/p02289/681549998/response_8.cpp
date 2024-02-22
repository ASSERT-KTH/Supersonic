#include <iostream>
#include <vector>

const int INFTY = (1 << 30);

void maxHeap(std::vector<int>& A, int i, int H) {
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
    maxHeap(A, large, H);
  }
}

int extract(std::vector<int>& A, int& H) {
  int maxv;
  if (H < 1)
    return -INFTY;
  maxv = A[1];
  A[1] = A[H--];
  maxHeap(A, 1, H);
  return maxv;
}

void increasekey(std::vector<int>& A, int i, int key) {
  if (key < A[i])
    return;
  A[i] = key;
  while (i > 1 && A[i / 2] < A[i]) {
    std::swap(A[i], A[i / 2]);
    i = i / 2;
  }
}

void insert(std::vector<int>& A, int& H, int key) {
  H++;
  A.push_back(-INFTY);
  increasekey(A, H, key);
}

int main() {
  int key;
  char com[10];
  std::vector<int> A;
  int H = 0;

  while (1) {
    std::cin >> com;
    if (com[0] == 'e' && com[1] == 'n')
      break;
    if (com[0] == 'i') {
      std::cin >> key;
      insert(A, H, key);
    } else {
      std::cout << extract(A, H) << std::endl;
    }
  }

  return 0;
}