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
static vector<uint32_t> L;
static vector<uint32_t> R;

static inline void merge(uint32_t A[], uint32_t left, uint32_t mid,
                         uint32_t right) {
  uint32_t n1 = mid - left;
  uint32_t n2 = right - mid;

  L.resize(n1);
  R.resize(n2);

  for (uint32_t i = 0; i < n1; i++) {
    L[i] = A[left + i];
  }

  for (uint32_t i = 0; i < n2; i++) {
    R[i] = A[mid + i];
  }

  L.push_back(UINT32_MAX);
  R.push_back(UINT32_MAX);

  uint32_t i = 0;
  uint32_t j = 0;
  uint32_t k = left;

  while (i < n1 || j < n2) {
    compared++;
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
    k++;
  }
}

static inline void mergeSort(uint32_t A[], uint32_t n) {
  if (n > 1) {
    uint32_t mid = n >> 1;
    mergeSort(A, mid);
    mergeSort(A + mid, n - mid);
    merge(A, 0, mid, n);
  }
}

int main() {
  int n;
  cin >> n;
  vector<uint32_t> A(n);
  inputArray(&A[0], n);
  mergeSort(&A[0], n);
  printArray(&A[0], n);
  cout << compared << endl;
  return 0;
}