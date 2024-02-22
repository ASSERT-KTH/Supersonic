#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

void inputArray(vector<uint32_t>& A) {
  for (auto& i : A) {
    cin >> i;
  }
}

void printArray(const vector<uint32_t>& A) {
  for (size_t i = 0; i < A.size(); i++) {
    if(i) cout << " ";
    cout << A[i];
  }
  cout << "\n";
}

uint32_t compared = 0;
void merge(vector<uint32_t>& A, vector<uint32_t>& L, vector<uint32_t>& R, uint32_t left, uint32_t mid, uint32_t right) {
  uint32_t n1 = mid - left;
  uint32_t n2 = right - mid;
  copy(A.begin() + left, A.begin() + mid, L.begin());
  copy(A.begin() + mid, A.begin() + right, R.begin());
  L[n1] = R[n2] = UINT32_MAX;

  for (uint32_t i = 0, j = 0, k = left; k < right; k++) {
    if (L[i] <= R[j]) {
      A[k] = L[i++];
      compared++;
    } else {
      A[k] = R[j++];
    }
  }
}

void mergeSort(vector<uint32_t>& A, vector<uint32_t>& L, vector<uint32_t>& R, uint32_t left, uint32_t right) {
  if (left + 1 < right) {
    uint32_t mid = (left + right) / 2;
    mergeSort(A, L, R, left, mid);
    mergeSort(A, L, R, mid, right);
    merge(A, L, R, left, mid, right);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<uint32_t> A(n), L(n), R(n);
  inputArray(A);
  mergeSort(A, L, R, 0, n);
  printArray(A);
  cout << compared << "\n";
  return 0;
}