#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

constexpr uint32_t MAX = UINT32_MAX;
constexpr size_t MAX_SIZE = 500000;
static uint32_t A[MAX_SIZE];
static uint32_t L[MAX_SIZE / 2 + 2], R[MAX_SIZE / 2 + 2];
static int compared = 0;

static inline void inputArray(uint32_t A[], int num) {
  for (int i = 0; i < num; i++) {
    cin >> A[i];
  }
}

static inline void printArray(uint32_t A[], int num) {
  for (int i = 0; i < num; i++) {
    if (i) cout << " ";
    cout << A[i];
  }
  cout << endl;
}

static inline void merge(uint32_t left, uint32_t mid, uint32_t right) {
  uint32_t n1 = mid - left;
  uint32_t n2 = right - mid;
  for (uint32_t i = 0; i < n1; i++) L[i] = A[left + i];
  for (uint32_t i = 0; i < n2; i++) R[i] = A[mid + i];
  L[n1] = R[n2] = MAX;
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

static inline void mergeSort(uint32_t left, uint32_t right) {
  if (left + 1 < right) {
    uint32_t mid = (left + right) / 2;
    mergeSort(left, mid);
    mergeSort(mid, right);
    merge(left, mid, right);
  }
}

int main() {
  int n;
  cin >> n;
  inputArray(A, n);
  mergeSort(0, n);
  printArray(A, n);
  cout << compared << endl;
  return 0;
}