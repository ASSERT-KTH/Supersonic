#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
#define INFTY (1 << 30)

class MaxHeap {
  private:
    vector<int> A;
  public:
    MaxHeap() {
        A.push_back(-INFTY);  // So that the heap starts from index 1
    }
    void maxHeapify(int i) {
      int largest;
      while (true) {
        int l = 2 * i;
        int r = 2 * i + 1;
        if (l < A.size() && A[l] > A[i]) {
          largest = l;
        } else {
          largest = i;
        }
        if (r < A.size() && A[r] > A[largest]) {
          largest = r;
        }
        if (largest != i) {
          swap(A[i], A[largest]);
          i = largest;
        } else {
          break;
        }
      }
    }
    int extract() {
      if (A.size() < 2)
        return -INFTY;
      int maxv = A[1];
      A[1] = A[A.size() - 1];
      A.pop_back();
      maxHeapify(1);
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
    void insert(int key) {
      A.push_back(-INFTY);
      increasekey(A.size() - 1, key);
    }
};

int main() {
  int key;
  char com[10];
  MaxHeap maxHeap;
  while (true) {
    scanf("%s", com);
    if (com[0] == 'e' && com[1] == 'n')
      break;
    if (com[0] == 'i') {
      scanf("%d", &key);
      maxHeap.insert(key);
    } else {
      printf("%d\n", maxHeap.extract());
    }
  }
  return 0;
}