#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

static vector<uint32_t> L(500000);
static vector<uint32_t> R(500000);

static inline void merge(uint32_t A[], uint32_t left, uint32_t mid, uint32_t right, int& compared) {
  uint32_t n1 = mid - left;
  uint32_t n2 = right - mid;
  for (uint32_t i = 0; i < n1; i++) L[i] = A[left + i];
  for (uint32_t j = 0; j < n2; j++) R[j] = A[mid + j];
  L[n1] = R[n2] = UINT32_MAX;
  uint32_t i = 0, j = 0;
  for (uint32_t k = left; k < right; k++) {
    compared++;
    if (L[i] <= R[j]) {
      A[k] = L[i++];
    } else {
      A[k] = R[j++];
    }
  }
}

static inline void mergeSort(uint32_t A[], uint32_t left, uint32_t right, int& compared) {
  if (left + 1 < right) {
    uint32_t mid = (left + right) / 2;
    mergeSort(A, left, mid, compared);
    mergeSort(A, mid, right, compared);
    merge(A, left, mid, right, compared);
  }
}

int main() {
  uint32_t n;
  cin >> n;
  vector<uint32_t> A(n);
  for (uint32_t& i : A) cin >> i;
  int compared = 0;
  mergeSort(A.data(), 0, n, compared);
  for (uint32_t i = 0; i < n; i++) {
    if (i) cout << ' ';
    cout << A[i];
  }
  cout << "\n" << compared << '\n';
  return 0;
}