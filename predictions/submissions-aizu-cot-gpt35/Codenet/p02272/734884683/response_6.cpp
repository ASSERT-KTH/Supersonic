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

static int compared = 0;

static inline void merge(uint32_t A[], uint32_t left, uint32_t mid,
                         uint32_t right) {
  uint32_t n1 = mid - left;
  uint32_t n2 = right - mid;
  uint32_t temp[n1 + n2];
  
  uint32_t* L = &A[left];
  uint32_t* R = &A[mid];
  
  uint32_t i = 0, j = 0, k = 0;
  while (i < n1 && j < n2) {
    compared++;
    if (L[i] <= R[j]) {
      temp[k++] = L[i++];
    } else {
      temp[k++] = R[j++];
    }
  }
  
  while (i < n1) {
    temp[k++] = L[i++];
  }
  
  while (j < n2) {
    temp[k++] = R[j++];
  }
  
  for (uint32_t m = 0; m < k; m++) {
    A[left + m] = temp[m];
  }
}

static inline void mergeSort(uint32_t A[], uint32_t left, uint32_t right) {
  if (left + 1 < right) {
    uint32_t mid = (left + right) >> 1;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main() {
  int n;
  cin >> n;
  
  uint32_t A[n];
  inputArray(A, n);
  
  mergeSort(A, 0, n);
  
  printArray(A, n);
  cout << compared << endl;
  
  return 0;
}