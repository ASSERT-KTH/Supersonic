#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;
static void inputArray(vector<uint32_t>& A, int num) {
  A.resize(num);
  for (int i = 0; i < num; i++) {
    cin >> A[i];
  }
}
static void printArray(const vector<uint32_t>& A) {
  for (int i = 0; i < A.size(); i++) {
    cout << (i != 0 ? " " : "") << A[i];
  }
  cout << endl;
}
static int compared = 0;
static vector<uint32_t> L(250001);
static vector<uint32_t> R(250001);
static inline void merge(vector<uint32_t>& A, uint32_t left, uint32_t mid,
                         uint32_t right) {
  uint32_t n1 = mid - left;
  uint32_t n2 = right - mid;
  for (uint32_t i = 0; i < n1; i++) {
    L[i] = A[left + i];
  }
  for (uint32_t i = 0; i < n2; i++) {
    R[i] = A[mid + i];
  }
  L[n1] = R[n2] = UINT32_MAX;
  for (uint32_t i = 0, j = 0, k = left; k < right; k++) {
    compared++;
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
  }
}
static inline void mergeSort(vector<uint32_t>& A, uint32_t left,
                             uint32_t right) {
  if (left + 1 < right) {
    uint32_t mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<uint32_t> A;
  inputArray(A, n);
  mergeSort(A, 0, n);
  printArray(A);
  cout << compared << endl;
  return 0;
}