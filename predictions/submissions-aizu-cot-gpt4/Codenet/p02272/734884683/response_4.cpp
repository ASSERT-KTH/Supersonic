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
    if (i) printf(" ");
    printf("%u", A[i]);
  }
  printf("\n");
}

static int compared = 0;
static vector<uint32_t> L;
static vector<uint32_t> R;

static inline void merge(uint32_t A[], uint32_t left, uint32_t mid, uint32_t right) {
  uint32_t n1 = mid - left;
  uint32_t n2 = right - mid;
  
  L.resize(n1+1);
  R.resize(n2+1);

  copy(&A[left], &A[left + n1], L.begin());
  copy(&A[mid], &A[mid + n2], R.begin());
  
  L[n1] = R[n2] = UINT32_MAX;
  
  for (uint32_t i = 0, j = 0, k = left; k < right; k++) {
    compared++;
    if (L[i] <= R[j]) {
      A[k] = L[i++];
    } else {
      A[k] = R[j++];
    }
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
  vector<uint32_t> A(n);
  inputArray(&A[0], n);
  mergeSort(&A[0], 0, n);
  printArray(&A[0], n);
  printf("%d\n", compared);
  return 0;
}