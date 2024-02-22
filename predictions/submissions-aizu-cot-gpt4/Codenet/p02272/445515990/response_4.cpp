#include <iostream>
using namespace std;
const int MAX = 500000;
int cnt;
int A[MAX] = {0};
void merge(int left, int mid) {
  int i = left, j = mid, k = 0;
  int temp[MAX];
  while (i < mid && j < 2 * mid - left) {
    if (A[i] <= A[j]) {
      temp[k] = A[i];
      i++;
    } else {
      temp[k] = A[j];
      j++;
    }
    k++;
    cnt++;
  }
  while (i < mid) {
    temp[k] = A[i];
    i++;
    k++;
    cnt++;
  }
  while (j < 2 * mid - left) {
    temp[k] = A[j];
    j++;
    k++;
    cnt++;
  }
  for (i = left; i < 2 * mid - left; i++) {
    A[i] = temp[i - left];
  }
}
void mergesort(int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergesort(left, mid);
    mergesort(mid, right);
    merge(left, mid);
  }
}
int main() {
  int N;
  cnt = 0;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    if (i > 0) {
      cout << " ";
    }
    cout << A[i];
  }
  cout << endl;
  mergesort(0, N);
  cout << cnt << endl;
  return 0;
}