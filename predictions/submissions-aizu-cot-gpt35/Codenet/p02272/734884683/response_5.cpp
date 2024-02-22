#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

static inline void merge(vector<uint32_t>& A, uint32_t left, uint32_t mid,
                         uint32_t right) {
  vector<uint32_t> L, R;
  L.reserve(mid - left + 1);
  R.reserve(right - mid + 1);

  for (uint32_t i = left; i <= mid; i++) {
    L.push_back(A[i]);
  }
  for (uint32_t i = mid + 1; i <= right; i++) {
    R.push_back(A[i]);
  }

  L.push_back(UINT32_MAX);
  R.push_back(UINT32_MAX);

  uint32_t i = 0, j = 0;
  for (uint32_t k = left; k <= right; k++) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
  }
}

static inline void mergeSort(vector<uint32_t>& A, uint32_t left, uint32_t right) {
  if (left < right) {
    uint32_t mid = left + (right - left) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid + 1, right);
    merge(A, left, mid, right);
  }
}

int main() {
  int n;
  cin >> n;
  vector<uint32_t> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  mergeSort(A, 0, n - 1);

  for (int i = 0; i < n; i++) {
    cout << (i != 0 ? " " : "") << A[i];
  }
  cout << endl;

  return 0;
}