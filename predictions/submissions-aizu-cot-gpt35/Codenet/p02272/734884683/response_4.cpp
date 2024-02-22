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
  cout << A[0];
  for (int i = 1; i < num; i++) {
    cout << " " << A[i];
  }
  cout << endl;
}

static inline void merge(uint32_t* A, uint32_t* left, uint32_t* mid, uint32_t* right) {
  uint32_t n1 = mid - left;
  uint32_t n2 = right - mid;
  vector<uint32_t> L(n1 + 1);
  vector<uint32_t> R(n2 + 1);
  for (uint32_t i = 0; i < n1; i++) {
    L[i] = left[i];
  }
  for (uint32_t i = 0; i < n2; i++) {
    R[i] = mid[i];
  }
  L[n1] = R[n2] = UINT32_MAX;

  for (uint32_t i = 0, j = 0, k = 0; k < (n1 + n2); k++) {
    if (L[i] <= R[j]) {
      *A = L[i];
      i++;
    } else {
      *A = R[j];
      j++;
    }
    A++;
  }
}

static inline void mergeSort(uint32_t* A, uint32_t* left, uint32_t* right) {
  if (left + 1 < right) {
    uint32_t* mid = left + (right - left) / 2;
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
  mergeSort(&A[0], &A[0], &A[n]);
  printArray(&A[0], n);
  return 0;
}