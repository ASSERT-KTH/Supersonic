#include <cstdint>
#include <iostream>
#include <vector>

static void inputArray(std::vector<uint32_t>& A) {
  for (auto& element : A) {
    std::cin >> element;
  }
}

static void printArray(const std::vector<uint32_t>& A) {
  for (std::size_t i = 0; i < A.size(); i++) {
    std::cout << (i != 0 ? " " : "") << A[i];
  }
  std::cout << std::endl;
}

static int compared = 0;

static inline void merge(std::vector<uint32_t>& A,
                         std::vector<uint32_t>::iterator left,
                         std::vector<uint32_t>::iterator mid,
                         std::vector<uint32_t>::iterator right) {
  std::vector<uint32_t> L(left, mid);
  std::vector<uint32_t> R(mid, right);

  L.reserve(mid - left + 1);
  R.reserve(right - mid + 1);

  L.push_back(UINT32_MAX);
  R.push_back(UINT32_MAX);

  auto i = L.begin();
  auto j = R.begin();

  for (auto it = left; it < right; it++) {
    compared++;
    if (*i <= *j) {
      *it = *i;
      i++;
    } else {
      *it = *j;
      j++;
    }
  }
}

static void mergeSort(std::vector<uint32_t>& A,
                      std::vector<uint32_t>::iterator left,
                      std::vector<uint32_t>::iterator right) {
  if (left + 1 < right) {
    auto mid = left + (right - left) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main() {
  int n;
  std::cin >> n;
  std::vector<uint32_t> A(n);
  inputArray(A);
  mergeSort(A, A.begin(), A.end());
  printArray(A);
  std::cout << compared << std::endl;
  return 0;
}