#include <cstdint>
#include <iostream>
#include <array>
using namespace std;
static void inputArray(uint32_t A[], int num) {
  for (int i = 0; i < num; i++) {
    cin >> A[i];
  }
}
static void printArray(uint32_t A[], int num) {
  for (int i = 0; i < num; i++) {
    cout << (i != 0 ? " " : "") << A[i];
  }
  cout << endl;
}
static int compared = 0;
static array<uint32_t, 250000> L;
static array<uint32_t, 250000> R;
static inline void merge(uint32_t A[], uint32_t left, uint32_t mid,
                         uint32_t right) {
  uint32_t n1 = mid - left;
  uint32_t n2 = right - mid;
  std::copy_n(&A[left], n1, L.begin());
  std::copy_n(&A[mid], n2, R.begin());
  L[n1] = R[n2] = UINT32_MAX;
  uint32_t i = 0, j = 0, k = left;
  for (; k < right; k++) {
    if (L[i] <= R[j]) {
      A[k] = L[i++];
    } else {
      A[k] = R[j++];
    }
  }
  compared += k - left;
}
static inline void mergeSort(uint32_t A[], uint32_t left, uint32_t right) {
  if (left + 1 < right) {
    uint32_t mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}
int main() {
  int n;
  cin >> n;
  vector<uint32_t> A(n);
  inputArray(&A[0], n);
  mergeSort(&A[0], 0, n);
  printArray(&A[0], n);
  cout << compared << endl;
  return 0;
}