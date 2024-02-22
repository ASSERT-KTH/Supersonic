#include <cstdio>
#include <iostream>
using namespace std;

const int INF = 1000000001;
const int MAX = 500000;

int cnt;
int S[MAX] = {0};

void merge(int *A, int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  int L[n1], R[n2];
  for (int i = 0; i < n1; i++) {
    L[i] = A[left + i];
  }
  for (int i = 0; i < n2; i++) {
    R[i] = A[mid + 1 + i];
  }

  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
    k++;
    cnt++;
  }

  while (i < n1) {
    A[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    A[k] = R[j];
    j++;
    k++;
  }
}

void insertionSort(int *A, int left, int right) {
  for (int i = left + 1; i <= right; i++) {
    int key = A[i];
    int j = i - 1;
    while (j >= left && A[j] > key) {
      A[j + 1] = A[j];
      j--;
      cnt++;
    }
    A[j + 1] = key;
  }
}

void mergesort(int *A, int left, int right) {
  if (left < right) {
    if (right - left <= 7) {
      insertionSort(A, left, right);
    } else {
      int mid = left + (right - left) / 2;
      mergesort(A, left, mid);
      mergesort(A, mid + 1, right);
      merge(A, left, mid, right);
    }
  }
}

int main() {
  int N;
  cnt = 0;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }
  mergesort(S, 0, N - 1);
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