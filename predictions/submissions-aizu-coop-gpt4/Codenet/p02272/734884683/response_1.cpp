#include <cstdint>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

static inline void merge(vector<uint32_t>& A, uint32_t left, uint32_t mid, uint32_t right, int& compared) {
    vector<uint32_t> temp;
    uint32_t i = left, j = mid;
    while(i < mid && j < right) {
        compared++;
        if(A[i] <= A[j]) {
            temp.push_back(A[i++]);
        } else {
            temp.push_back(A[j++]);
        }
    }
    while(i < mid) {
        temp.push_back(A[i++]);
    }
    while(j < right) {
        temp.push_back(A[j++]);
    }
    for(i=left; i<right; ++i) {
        A[i] = temp[i-left];
    }
}

static inline void mergeSort(vector<uint32_t>& A, uint32_t left, uint32_t right, int& compared) {
  if (left + 1 < right) {
    uint32_t mid = (left + right) / 2;
    mergeSort(A, left, mid, compared);
    mergeSort(A, mid, right, compared);
    merge(A, left, mid, right, compared);
  }
}

int main() {
  int n;
  cin >> n;
  vector<uint32_t> A(n);
  copy(istream_iterator<uint32_t>(cin), istream_iterator<uint32_t>(), back_inserter(A));
  int compared = 0;
  mergeSort(A, 0, n, compared);
  copy(A.begin(), A.end(), ostream_iterator<uint32_t>(cout, " "));
  cout << endl << compared << endl;
  return 0;
}