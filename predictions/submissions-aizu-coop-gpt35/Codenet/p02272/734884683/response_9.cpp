#include <cstdint>
#include <iostream>
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

static inline void merge(uint32_t A[], uint32_t left, uint32_t mid,
                         uint32_t right) {
  uint32_t n1 = mid - left;
  uint32_t n2 = right - mid;

  uint32_t* L = new uint32_t[n1];
  uint32_t* R = new uint32_t[n2];

  for (uint32_t i = 0; i < n1; i++) {
    L[i] = A[left + i];
  }

  for (uint32_t i = 0; i < n2; i++) {
    R[i] = A[mid + i];
  }

  uint32_t i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      A[k] = L[i++];
    } else {
      A[k] = R[j++];
    }
    k++;
  }

  while (i < n1) {
    A[k++] = L[i++];
  }

  while (j < n2) {
    A[k++] = R[j++];
  }

  delete[] L;
  delete[] R;
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

  uint32_t* A = new uint32_t[n];
  inputArray(A, n);

  mergeSort(A, 0, n);

  printArray(A, n);

  delete[] A;

  return 0;
}