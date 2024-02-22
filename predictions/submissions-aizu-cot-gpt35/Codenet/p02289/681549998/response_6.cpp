#include <iostream>
using namespace std;

const int MAX = 2000000;
const int INFTY = 1e9;

void maxHeap(int H, int A[], int i) {
  int l, r, large;
  while (true) {
    l = 2 * i;
    r = 2 * i + 1;
    large = i;

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

int extract(int& H, int A[]) {
  if (H < 1) {
    return -INFTY;
  }

  int maxv = A[1];
  A[1] = A[H--];
  maxHeap(H, A, 1);
  return maxv;
}

void increasekey(int A[], int i, int key) {
  if (key < A[i]) {
    return;
  }

  A[i] = key;
  while (i > 1 && A[i / 2] < A[i]) {
    swap(A[i], A[i / 2]);
    i = i / 2;
  }
}

void insert(int& H, int A[], int key) {
  A[++H] = -INFTY;
  increasekey(A, H, key);
}

int main() {
  ios_base::sync_with_stdio(false);

  int H = 0;
  int A[MAX + 1];
  int key;
  char com[10];

  while (true) {
    cin >> com;
    if (com[0] == 'e' && com[1] == 'n') {
      break;
    }
    if (com[0] == 'i') {
      cin >> key;
      insert(H, A, key);
    } else {
      cout << extract(H, A) << endl;
    }
  }

  return 0;
}