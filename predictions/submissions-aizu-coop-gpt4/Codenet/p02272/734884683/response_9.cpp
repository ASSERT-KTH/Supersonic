#include <cstdint>
#include <cstdio>
using namespace std;

static void inputArray(uint32_t A[], int num) {
  for (int i = 0; i < num; i++) {
    scanf("%u", &A[i]);
  }
}

static void printArray(uint32_t A[], int num) {
  for (int i = 0; i < num; i++) {
    if (i != 0)
      printf(" ");
    printf("%u", A[i]);
  }
  printf("\n");
}

static int compared = 0;

static inline void merge(uint32_t A[], uint32_t left, uint32_t mid,
                         uint32_t right) {
  uint32_t n1 = mid - left;
  uint32_t n2 = right - mid;
  uint32_t i = 0, j = 0, k = left;
  while (k < right) {
    compared++;
    if (i < n1 && (j >= n2 || A[left + i] <= A[mid + j])) {
      A[k] = A[left + i];
      i++;
    } else {
      A[k] = A[mid + j];
      j++;
    }
    k++;
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
  scanf("%d", &n);
  uint32_t A[n];
  inputArray(A, n);
  mergeSort(A, 0, n);
  printArray(A, n);
  printf("%d\n", compared);
  return 0;
}