#include <cstdint>
#include <iostream>
#include <vector>
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
static vector<uint32_t> L(250000);
static vector<uint32_t> R(220000);
static inline void merge(uint32_t A[], uint32_t left, uint32_t mid,
                         uint32_t right) {
  uint32_t n1 = mid - left;
  uint32_t n2 = right - mid;
  L.assign(&A[left], &A[left + n1]);
  R.assign(&A[mid], &A[mid + n2]);
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
static inline void mergeSort(uint32_t A[], uint32_t left, uint32_t right) {
  if (left + 1 < right) {
    uint32_t mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right