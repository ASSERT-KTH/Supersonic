#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

static inline void merge(vector<uint32_t>& A, uint32_t left, uint32_t mid, uint32_t right, int& compared) {
  uint32_t i = left, j = mid, k = left;
  while (k < right) {
    compared++;
    if (A[i] <= A[j]) {
      i++;
    } else {
      swap(A[k], A[j]);
      j++;
    }
    k++;
  }
}

static inline void mergeSort(vector<uint32_t>& A, uint32_t left, uint32_t right, int& compared) {
  if (left + 1 < right) {
    uint32_t mid = (left + right) / 2;
    mergeSort(A, left, mid, compared);
    mergeSort(A, mid, right, compared);
    merge(A, left, mid, right, compared);
  }
}

int main() {
  int n;
  cin >> n;
  vector<uint32_t> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  int compared = 0;
  mergeSort(A, 0, n, compared);
  for (int i = 0; i < n; i++) {
    cout << (i != 0 ? " " : "") << A[i];
  }
  cout << endl;
  cout << compared << endl;
  return 0;
}