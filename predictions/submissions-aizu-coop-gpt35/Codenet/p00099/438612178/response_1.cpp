#include <cstdio>
#include <iostream>
using namespace std;
const int MAX = 1000001;
int S[MAX];
int heap[MAX];
int size = 0;

void percolateUp(int idx) {
  int parent = idx / 2;
  while (parent > 0 && S[heap[parent]] < S[heap[idx]]) {
    swap(heap[parent], heap[idx]);
    idx = parent;
    parent = idx / 2;
  }
}

void percolateDown(int idx) {
  int child = idx * 2;
  while (child <= size) {
    if (child + 1 <= size && S[heap[child + 1]] > S[heap[child]]) {
      child++;
    }
    if (S[heap[idx]] >= S[heap[child]]) {
      break;
    }
    swap(heap[idx], heap[child]);
    idx = child;
    child = idx * 2;
  }
}

void updateHeap(int num) {
  for (int i = 1; i <= size; i++) {
    if (heap[i] == num) {
      percolateUp(i);
      percolateDown(i);
      break;
    }
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  heap[0] = 0;  // dummy element
  while (m--) {
    int a, b;
    scanf("%d %d", &a, &b);
    S[a] += b;
    updateHeap(a);
    if (S[heap[1]] == S[a]) {
      cout << heap[1] << " " << S[a] << endl;
    }
  }
  return 0;
}