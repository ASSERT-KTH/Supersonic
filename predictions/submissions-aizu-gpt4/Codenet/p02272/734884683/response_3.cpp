#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;
static void inputArray(vector<uint32_t> &A) {
  for (auto &a : A) {
    cin >> a;
  }
}
static void printArray(const vector<uint32_t> &A) {
  for (size_t i = 0; i < A.size(); ++i) {
    if (i != 0) cout << " ";
    cout << A[i];
  }
  cout << endl;
}
static int compared = 0;
static void merge(vector<uint32_t> &A, size_t left, size_t mid, size_t right) {
  vector<uint32_t> L(A.begin() + left, A.begin() + mid);
  vector<uint32_t> R(A.begin() + mid, A.begin() + right);
  L.push_back(UINT32_MAX);
  R.push_back(UINT32_MAX);
  for (size_t i = 0, j = 0, k = left; k < right; ++k) {
    ++compared;
    if (L[i] <= R[j]) {
      A[k] = std::move(L[i++]);
    } else {
      A[k] = std::move(R[j++]);
    }
  }
}
static void mergeSort(vector<uint32_t> &A, size_t left, size_t right) {
  if (left + 1 < right) {
    size_t mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}
int main() {
  size_t n;
  cin >> n;
  vector<uint32_t> A(n);
  inputArray(A);
  mergeSort(A, 0, n);
  printArray(A);
  cout << compared << endl;
  return 0;
}