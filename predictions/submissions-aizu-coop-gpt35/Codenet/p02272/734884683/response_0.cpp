#include <array>
#include <cstdint>
#include <iostream>
#include <stack>

static void inputArray(uint32_t A[], int num) {
  for (int i = 0; i < num; i++) {
    std::cin >> A[i];
  }
}

static void printArray(uint32_t A[], int num) {
  for (int i = 0; i < num; i++) {
    std::cout << (i != 0 ? " " : "") << A[i];
  }
  std::cout << std::endl;
}

static int compared = 0;
static std::array<uint32_t, 250000> L;
static std::array<uint32_t, 250000> R;

static inline void merge(uint32_t A[], uint32_t left, uint32_t mid,
                         uint32_t right) {
  uint32_t n1 = mid - left;
  uint32_t n2 = right - mid;
  L = {A + left, A + left + n1};
  R = {A + mid, A + mid + n2};
  L[n1] = R[n2] = UINT32_MAX;

  for (uint32_t i = 0, j = 0, k = left; k < right; k += 4) {
    compared += 4;

    uint32_t l0 = L[i];
    uint32_t l1 = L[i + 1];
    uint32_t l2 = L[i + 2];
    uint32_t l3 = L[i + 3];

    uint32_t r0 = R[j];
    uint32_t r1 = R[j + 1];
    uint32_t r2 = R[j + 2];
    uint32_t r3 = R[j + 3];

    if (l0 <= r0) {
      A[k] = l0;
      i++;
    } else {
      A[k] = r0;
      j++;
    }

    if (l1 <= r1) {
      A[k + 1] = l1;
      i++;
    } else {
      A[k + 1] = r1;
      j++;
    }

    if (l2 <= r2) {
      A[k + 2] = l2;
      i++;
    } else {
      A[k + 2] = r2;
      j++;
    }

    if (l3 <= r3) {
      A[k + 3] = l3;
      i++;
    } else {
      A[k + 3] = r3;
      j++;
    }
  }
}

static inline void mergeSort(uint32_t A[], uint32_t left, uint32_t right) {
  std::stack<std::pair<uint32_t, uint32_t>> stack;
  stack.push({left, right});

  while (!stack.empty()) {
    left = stack.top().first;
    right = stack.top().second;
    stack.pop();

    if (left + 1 < right) {
      uint32_t mid = (left + right) / 2;
      stack.push({left, mid});
      stack.push({mid, right});
    } else {
      // Use insertion sort for small subarrays
      if (right - left <= 16) {
        for (uint32_t i = left + 1; i < right; i++) {
          uint32_t key = A[i];
          int32_t j = i - 1;
          while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
          }
          A[j + 1] = key;
        }
      }
    }
  }

  // Perform merging
  while (stack.size() > 1) {
    uint32_t mid = stack.top().second;
    stack.pop();
    uint32_t left = stack.top().first;
    stack.pop();
    merge(A, left, mid, stack.top().second);
  }
}

int main() {
  int n;
  std::cin >> n;
  std::array<uint32_t, 250000> A;
  inputArray(&A[0], n);
  mergeSort(&A[0], 0, n);
  printArray(&A[0], n);
  std::cout << compared << std::endl;
  return 0;
}