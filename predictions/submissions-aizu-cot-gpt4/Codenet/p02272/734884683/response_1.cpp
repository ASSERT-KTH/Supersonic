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
    if (i != 0) cout << " ";
    cout << A[i];
  }
  cout << endl;
}

static void merge(uint32_t A[], uint32_t left, uint32_t mid, uint32_t right) {
  vector<uint32_t> temp(right - left);
  uint32_t i = left, j = mid, k = 0;
  while (i < mid && j < right) {
    if (A[i] <= A[j]) {
      temp[k++] = A[i++];
    } else {
      temp[k++] = A[j++];
    }
  }
  while (i < mid) {
    temp[k++] = A[i++];
  }
  while (j < right) {
    temp[k++] = A[j++];
  }
  for (i = left, k = 0; i < right;) {
    A[i++] = temp[k++];
  }
}

static void mergeSort(uint32_t A[], uint32_t left, uint32_t right) {
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
  return 0;
}