#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
const int INF = 1000000001;
const int MAX = 500000;
int cnt;

void merge(int *A, int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  int L[n1 + 1], R[n2 + 1]; // Use temporary arrays for merging

  for (int i = 0; i < n1; i++) {
    L[i] = A[left + i];
  }
  for (int i = 0; i < n2; i++) {
    R[i] = A[mid + i];
  }
  L[n1] = R[n2] = INF;

  int i = 0, j = 0, k = left;
  while (k < right) {
    if (L[i] <= R[j]) {
      A[k++] = L[i++];
    } else {
      A[k++] = R[j++];
    }
    cnt++;
  }
}

void mergesort(int *A, int left, int right) {
  if (left + 1 >= right) {
    return; // Base case, already sorted
  }
  
  int mid = left + (right - left) / 2;
  mergesort(A, left, mid);
  mergesort(A, mid, right);
  merge(A, left, mid, right);
}

int main() {
  int N;
  cnt = 0;
  cin >> N;
  int S[N];
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }
  mergesort(S, 0, N);
  for (int i = 0; i < N; i++) {
    if (i == N - 1) {
      cout << S[i] << endl;
    } else {
      cout << S[i] << " ";
    }
  }
  cout << cnt << endl;
  return 0;
}