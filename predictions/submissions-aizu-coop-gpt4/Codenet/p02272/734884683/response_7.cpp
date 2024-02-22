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

static uint32_t L[250000];
static uint32_t R[250000];

static inline void merge(uint32_t A[], uint32_t left, uint32_t mid,
                         uint32_t right, uint32_t &compared) {
  uint32_t n1 = mid - left;
  uint32_t n2 = right - mid;
  for (uint32_t i = 0; i < n1; i++)
    L[i] = A[left + i];
  for (uint32_t i = 0; i < n2; i++)
    R[i] = A[mid + i];
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

static inline void mergeSort(uint32_t A[], uint32_t left, uint32_t right, uint32_t &compared) {
  if (left + 1 < right) {
    uint32_t mid = (left + right) / 2;
    mergeSort(A, left, mid, compared);
    mergeSort(A, mid, right, compared);
    merge(A, left, mid, right, compared);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  uint32_t A[n];
  inputArray(A, n);
  uint32_t compared = 0;
  mergeSort(A, 0, n, compared);
  printArray(A, n);
  cout << compared << endl;
  return 0;
}