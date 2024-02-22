#include <cstdint>
#include <cstdio>
#include <vector>
using namespace std;

static void inputArray(uint32_t A[], int num) {
  for (int i = 0; i < num; i++) {
    scanf("%u", &A[i]);
  }
}

static void printArray(uint32_t A[], int num) {
  for (int i = 0; i < num; i++) {
    printf("%u%c", A[i], i != num - 1 ? ' ' : '\n');
  }
}

static int compared = 0;

static inline void merge(uint32_t A[], uint32_t left, uint32_t mid, uint32_t right) {
  uint32_t n1 = mid - left;
  uint32_t n2 = right - mid;
  vector<uint32_t> L(A + left, A + mid);
  vector<uint32_t> R(A + mid, A + right);
  L.push_back(UINT32_MAX);
  R.push_back(UINT32_MAX);
  uint32_t i = 0, j = 0;
  for (uint32_t k = left; k < right; k++) {
    if (L[i] <= R[j]) {
      A[k] = L[i++];
    } else {
      A[k] = R[j++];
    }
  }
  compared += right - left;
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
  scanf("%d", &n);
  vector<uint32_t> A(n);
  inputArray(&A[0], n);
  mergeSort(&A[0], 0, n);
  printArray(&A[0], n);
  printf("%d\n", compared);
  return 0;
}