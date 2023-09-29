#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

static vector<uint32_t> L(500001);
static vector<uint32_t> R(500001);

static inline void merge(vector<uint32_t>& A, uint32_t left, uint32_t mid,
                         uint32_t right, uint32_t& compared) {
  uint32_t n1 = mid - left;
  uint32_t n2 = right - mid;
  copy(A.begin() + left, A.begin() + mid, L.begin());
  copy(A.begin() + mid, A.begin() + right, R.begin());
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

static inline void mergeSort(vector<uint32_t>& A, uint32_t left, uint32_t right, uint32_t& compared) {
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
  for(auto& elem : A) cin >> elem;
  uint32_t compared = 0;
  mergeSort(A, 0, n, compared);
  for(size_t i = 0; i < A.size(); ++i) {
    if (i) cout << " ";
    cout << A[i];
  }
  cout << "\n" << compared << endl;
  return 0;
}