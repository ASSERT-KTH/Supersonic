#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

void inputArray(uint32_t A[], int num) {
  for (int i = 0; i < num; i++) {
    cin >> A[i];
  }
}

void printArray(uint32_t A[], int num) {
  for (int i = 0; i < num; i++) {
    cout << (i != 0 ? " " : "") << A[i];
  }
  cout << endl;
}

int compared = 0;

void merge(uint32_t A[], uint32_t left, uint32_t mid, uint32_t right) {
  vector<uint32_t> L(mid - left + 1, UINT32_MAX);
  vector<uint32_t> R(right - mid + 1, UINT32_MAX);
  
  copy(A + left, A + mid, L.begin());
  copy(A + mid, A + right, R.begin());

  for (uint32_t i = 0, j = 0, k = left; k < right; k++) {
    compared++;
    if (L[i] <= R[j]) {
      A[k] = L[i];
      ++i;
    } else {
      A[k] = R[j];
      ++j;
    }
  }
}

void mergeSort(uint32_t A[], uint32_t left, uint32_t right) {
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
  vector<uint32_t> A(n);
  inputArray(&A[0], n);
  mergeSort(&A[0], 0, n);
  printArray(&A[0], n);
  cout << compared << endl;
  return 0;
}