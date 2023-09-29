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
  for (size_t i = 0; i < A.size(); i++) {
    cout << (i != 0 ? " " : "") << A[i];
  }
  cout << endl;
}
static int compared = 0;
static vector<uint32_t> L(250000);
static vector<uint32_t> R(250000);
static inline void merge(vector<uint32_t>& A, uint32_t left, uint32_t mid,
                         uint32_t right) {
  uint32_t n1 = mid - left;
  uint32_t n2 = right - mid;
  L.resize(n1 + 1);
  R.resize(n2 + 1);
  copy(&A[left], &A[left + n1], &L[0]);
  copy(&A[mid], &A[mid + n2], &R[0]);
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
static inline void mergeSort(vector<uint32_t>& A, uint32_t left, uint32_t right) {
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
  vector<uint32_t> A;
  inputArray(A, n);
  mergeSort(A, 0, n);
  printArray(A);
  cout << compared << endl;
  return 0;
}