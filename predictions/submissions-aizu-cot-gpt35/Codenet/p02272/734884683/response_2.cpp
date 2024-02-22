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

static inline void merge(uint32_t A[], uint32_t left, uint32_t mid,
                         uint32_t right) {
  uint32_t n1 = mid - left;
  uint32_t n2 = right - mid;
  vector<uint32_t> L;
  vector<uint32_t> R;
  L.reserve(n1);
  R.reserve(n2);
  for (uint32_t i = 0; i < n1; i++) {
    L.push_back(A[left + i]);
  }
  for (uint32_t j = 0; j < n2; j++) {
    R.push_back(A[mid + j]);
  }
  uint32_t* pL = &L[0];
  uint32_t* pR = &R[0];
  uint32_t* pA = &A[left];
  uint32_t* pLend = pL + n1;
  uint32_t* pRend = pR + n2;
  while (pL < pLend && pR < pRend) {
    if (*pL <= *pR) {
      *pA = *pL;
      pL++;
    } else {
      *pA = *pR;
      pR++;
    }
    pA++;
  }
  while (pL < pLend) {
    *pA = *pL;
    pL++;
    pA++;
  }
  while (pR < pRend) {
    *pA = *pR;
    pR++;
    pA++;
  }
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
  vector<uint32_t> A;
  A.reserve(n);
  inputArray(&A[0], n);
  mergeSort(&A[0], 0, n);
  printArray(&A[0], n);
  vector<uint32_t>().swap(A);
  return 0;
}