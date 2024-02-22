#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define INFTY (1 << 30)
int H = 0;
vector<int> A(1);
set<int> keys;

void maxHeap(int i) {
  int large;
  while (true) {
    int l = 2 * i;
    int r = 2 * i + 1;
    if (l <= H && A[l] > A[i])
      large = l;
    else
      large = i;
    if (r <= H && A[r] > A[large])
      large = r;

    if (large != i) {
      swap(A[i], A[large]);
      i = large;
    } else {
      break;
    }
  }
}
int extract() {
  if (H < 1) return -INFTY;
  int maxv = A[1];
  keys.erase(maxv);
  A[1] = A[H--];
  A.pop_back();
  maxHeap(1);
  return maxv;
}
void increasekey(int i, int key) {
  if (key < A[i] || keys.count(key)) return;
  A[i] = key;
  keys.insert(key);
  while (i > 1 && A[i / 2] < A[i]) {
    swap(A[i], A[i / 2]);
    i = i / 2;
  }
}
void insert(int key) {
  if (keys.count(key)) return;
  A.push_back(-INFTY);
  H++;
  increasekey(H, key);
}
int main() {
  int key;
  char com;
  while (1) {
    cin >> com;
    if (com == 'e') break;
    switch (com) {
      case 'i':
        cin >> key;
        insert(key);
        break;
      case 'x':
        cout << extract() << endl;
        break;
      default:
        break;
    }
  }
  return 0;
}