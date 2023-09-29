#include <iostream>
#include <vector>
using namespace std;

static void inputArray(vector<uint32_t>& A, int num) {
  A.resize(num);
  for (int i = 0; i < num; i++) {
    cin >> A[i];
  }
}

static void printArray(const vector<uint32_t>& A) {
  int num = A.size();
  for (int i = 0; i < num; i++) {
    cout << (i != 0 ? " " : "") << A[i];
  }
  cout << endl;
}

static int compared = 0;

static vector<uint32_t> L;
static vector<uint32_t> R;

static void merge(vector<uint32_t>& A, int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;

  L.resize(n1 + 1);
  R.resize(n2 + 1);

  for (int i = 0; i < n1; i++) {
    L[i] = A[left + i];
  }
  for (int i = 0; i < n2; i++) {
    R[i] = A[mid + i];
  }

  L[n1] = R[n2] = UINT32_MAX;

  int i = 0, j = 0;
  for (int k = left; k < right; k++) {
    compared++;
    if (L[i] <= R[j]) {
      A[k] = L[i++];
    } else {
      A[k] = R[j++];
    }
  }
}

static void mergeSort(vector<uint32_t>& A, int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<uint32_t> A;
  inputArray(A, n);

  mergeSort(A, 0, n);

  printArray(A);

  cout << compared << endl;

  return 0;
}