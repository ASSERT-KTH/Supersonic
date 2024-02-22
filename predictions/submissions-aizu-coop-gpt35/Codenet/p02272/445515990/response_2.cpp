#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
const int INF = 1000000001;
const int MAX = 500000;
int cnt;

void merge(int *A, int left, int mid, int right, int *temp) {
  int n1 = mid - left;
  int n2 = right - mid;
  int i = 0, j = 0, k = 0;

  while (i < n1 && j < n2) {
    if (A[left + i] <= A[mid + j]) {
      temp[k++] = A[left + i++];
    } else {
      temp[k++] = A[mid + j++];
    }
    cnt++;
  }

  while (i < n1) {
    temp[k++] = A[left + i++];
  }

  while (j < n2) {
    temp[k++] = A[mid + j++];
  }

  for (int i = 0; i < k; i++) {
    A[left + i] = temp[i];
  }
}

void mergesort(int *A, int left, int right, int *temp) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergesort(A, left, mid, temp);
    mergesort(A, mid, right, temp);
    merge(A, left, mid, right, temp);
  }
}

int main() {
  int N;
  cnt = 0;
  cin >> N;
  int *S = new int[N];
  int *temp = new int[N];
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }
  mergesort(S, 0, N, temp);
  for (int i = 0; i < N; i++) {
    if (i == N - 1) {
      cout << S[i] << endl;
    } else {
      cout << S[i] << " ";
    }
  }
  cout << cnt << endl;
  delete[] S;
  delete[] temp;
  return 0;
}