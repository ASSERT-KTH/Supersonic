#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define MAX 2000000
#define INFTY (1 << 30)
int H, A[MAX + 1];

// Iterative version of maxHeap.
void maxHeap(int i) {
  while (true) {
    int l = 2 * i;
    int r = 2 * i + 1;
    int largest = i;

    if (l <= H && A[l] > A[largest]) 
      largest = l;

    if (r <= H && A[r] > A[largest]) 
      largest = r;

    if (largest != i) {
      swap(A[i], A[largest]);
      i = largest;
    } else {
      break;
    }
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
    swap(A[i], A[i / 2]);
    i = i / 2;
  }
}

// Insert key value directly.
void insert(int key) {
  H++;
  A[H] = key;
  increasekey(H, key);
}

int main() {
  int key;
  char com[10];
  while (1) {
    cin >> com;
    if (com[0] == 'e' && com[1] == 'n')
      break;
    if (com[0] == 'i') {
      cin >> key;
      insert(key);
    } else {
      cout << extract() << endl;
    }
  }
  return 0;
}