#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

static int compared = 0;
static vector<uint32_t> buf;

static void mergeSort(vector<uint32_t>& A, uint32_t left, uint32_t right) {
  if (right - left <= 1) return;
  uint32_t mid = (left + right) / 2;
  mergeSort(A, left, mid);
  mergeSort(A, mid, right);
  copy(A.begin() + left, A.begin() + mid, buf.begin());
  uint32_t i = left, j = mid, k = 0;
  while (i < mid && j < right) {
    compared++;
    if (buf[k] <= A[j]) {
      A[i++] = buf[k++];
    } else {
      A[i++] = A[j++];
    }
  }
  copy(buf.begin(), buf.begin() + k, A.begin() + left);
}

int main() {
  int n;
  cin >> n;
  vector<uint32_t> A(n);
  for (auto& a : A) cin >> a;
  buf.resize(n);
  mergeSort(A, 0, n);
  for (const auto& a : A) cout << a << ' ';
  cout << '\n' << compared << '\n';
  return 0;
}