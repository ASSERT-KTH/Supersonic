#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INFTY (1 << 30)

vector<int> A(1);
int H = 0;

void maxHeap(int i) {
  while (1) {
    int l = 2 * i;
    int r = 2 * i + 1;
    int largest;

    if (l <= H && A[l] > A[i]) largest = l;
    else largest = i;

    if (r <= H && A[r] > A[largest]) largest = r;

    if (largest == i) break;

    swap(A[i], A[largest]);
    i = largest;
  }
}

int extract() {
  if (H < 1) return -INFTY;
  int maxv = A[1];
  A[1] = A[H--];
  maxHeap(1);
  return maxv;
}

void increasekey(int i, int key) {
  A[i] = key;
  while (i > 1 && A[i / 2] < A[i]) {
    swap(A[i], A[i / 2]);
    i = i / 2;
  }
}

void insert(int key) {
  H++;
  if (H >= (int)A.size()) A.resize(A.size()*2);
  A[H] = -INFTY;
  increasekey(H, key);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int key;
  string com;

  do {
    cin >> com;
    if (com[0] == 'i') {
      cin >> key;
      insert(key);
    } else if (com[0] == 'e' && com[1] != 'n') {
      cout << extract() << "\n";
    }
  } while (com[0] != 'e' || com[1] != 'n');

  return 0;
}