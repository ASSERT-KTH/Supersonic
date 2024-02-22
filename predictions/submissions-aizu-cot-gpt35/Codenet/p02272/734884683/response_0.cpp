#include <iostream>
#include <vector>

using namespace std;

static void inputArray(vector<uint32_t>& A) {
  for (auto& num : A) {
    cin >> num;
  }
}

static void printArray(const vector<uint32_t>& A) {
  for (size_t i = 0; i < A.size(); i++) {
    cout << (i != 0 ? " " : "") << A[i];
  }
  cout << endl;
}

static int compared = 0;

static inline void merge(vector<uint32_t>& A, size_t left, size_t mid,
                         size_t right) {
  size_t n1 = mid - left;
  size_t n2 = right - mid;

  vector<uint32_t> L(A.begin() + left, A.begin() + left + n1);
  vector<uint32_t> R(A.begin() + mid, A.begin() + mid + n2);
  L.push_back(UINT32_MAX);
  R.push_back(UINT32_MAX);

  for (size_t i = 0, j = 0, k = left; k < right; k++) {
    compared++;
    if (L[i] <= R[j]) {
      A[k] = L[i++];
    } else {
      A[k] = R[j++];
    }
  }
}

static inline void mergeSort(vector<uint32_t>& A, size_t left, size_t right) {
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