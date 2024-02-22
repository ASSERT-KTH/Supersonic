#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> A(1,0);
int H = 0;

void maxHeap(int i) {
  while (true) {
    int l = 2 * i;
    int r = 2 * i + 1;
    int largest = (l <= H && A[l] > A[i]) ? l : i;
    largest = (r <= H && A[r] > A[largest]) ? r : largest;
    if (largest == i) break;
    swap(A[i], A[largest]);
    i = largest;
  }
}

int extract() {
  if (H < 1) return -1;
  int maxVal = A[1];
  A[1] = A[H--];
  A.pop_back();
  maxHeap(1);
  return maxVal;
}

void increasekey(int i, int key) {
  A[i] = key;
  while (i > 1 && A[i / 2] < A[i]) {
    swap(A[i], A[i / 2]);
    i = i / 2;
  }
}

void insert(int key) {
  A.push_back(-1);
  H++;
  increasekey(H, key);
}

int main() {
  char cmd;
  while (cin >> cmd) {
    switch (cmd) {
      case 'i': {
        int key;
        cin >> key;
        insert(key);
        break;
      }
      case 'e': {
        cout << extract() << endl;
        break;
      }
      default: {
        return 0;
      }
    }
  }
  return 0;
}