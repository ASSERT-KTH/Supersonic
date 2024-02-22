#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

static void inputArray(vector<uint32_t>& A, int num) {
  for (int i = 0; i < num; i++) {
    cin >> A[i];
  }
}

static void printArray(const vector<uint32_t>& A, int num) {
  cout << A[0];
  for (int i = 1; i < num; i++) {
    cout << " " << A[i];
  }
  cout << endl;
}

static int compared = 0;
static inline void merge(vector<uint32_t>& A, vector<uint32_t>& aux, uint32_t left, uint32_t mid, uint32_t right) {
  uint32_t n1 = mid - left;
  uint32_t n2 = right - mid;
  
  copy(A.begin() + left, A.begin() + mid, aux.begin());
  copy(A.begin() + mid, A.begin() + right, aux.begin() + n1);
  
  aux[n1] = aux[n1 + n2] = UINT32_MAX;
  
  for (uint32_t i = 0, j = 0, k = left; k < right; k++) {
    compared++;
    if (aux[i] <= aux[n1 + j]) {
      A[k] = aux[i++];
    } else {
      A[k] = aux[n1 + j++];
    }
  }
}

static inline void mergeSort(vector<uint32_t>& A, uint32_t left, uint32_t right) {
  if (left + 1 < right) {
    uint32_t mid = (left + right) / 2;
    vector<uint32_t> aux(A.size());
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, aux, left, mid, right);
  }
}

int main() {
  int n;
  cin >> n;
  vector<uint32_t> A(n);
  inputArray(A, n);
  mergeSort(A, 0, n);
  printArray(A, n);
  cout << compared << endl;
  return 0;
}