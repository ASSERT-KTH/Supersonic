#include <cstdint>
#include <cstdio>
#include <vector>
using namespace std;

static void inputArray(vector<uint32_t>& A, int num) {
  for (int i = 0; i < num; i++) {
    scanf("%u", &A[i]);
  }
}

static void printArray(const vector<uint32_t>& A, int num) {
  for (int i = 0; i < num; i++) {
    printf((i != 0 ? " %u" : "%u"), A[i]);
  }
  printf("\n");
}

static int compared = 0;

static inline void merge(vector<uint32_t>& A, uint32_t left, uint32_t mid, uint32_t right) {
  uint32_t n1 = mid - left;
  uint32_t n2 = right - mid;
  vector<uint32_t> L(A.begin() + left, A.begin() + mid);
  vector<uint32_t> R(A.begin() + mid, A.begin() + right);
  uint32_t i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    compared++;
    if (L[i] <= R[j]) {
      A[k++] = L[i++];
    } else {
      A[k++] = R[j++];
    }
  }
  while (i < n1) {
    A[k++] = L[i++];
  }
  while (j < n2) {
    A[k++] = R[j++];
  }
}

static inline void mergeSort(vector<uint32_t>& A, uint32_t left, uint32_t right) {
  if (left + 1 < right) {
    uint32_t mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  vector<uint32_t> A(n);
  inputArray(A, n);
  mergeSort(A, 0, n);
  printArray(A, n);
  printf("%d\n", compared);
  return 0;
}