#include <iostream>
const int INF = 1000000001;
const int MAX = 500000;
int cnt;
int S[MAX] = {0}, L[1 + MAX / 2] = {0}, R[1 + MAX / 2] = {0};

void merge(int* A, int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;

  for (int i = 0; i < n1; i++) {
    L[i] = A[left + i];
  }
  for (int i = 0; i < n2; i++) {
    R[i] = A[mid + i];
  }
  L[n1] = INF;
  R[n2] = INF;

  int i = 0;
  int j = 0;
  for (int k = left; k < right; k++) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
    cnt++;
  }
}

void mergesort(int* A, int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergesort(A, left, mid);
    mergesort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main() {
  int N;
  cnt = 0;
  std::cin >> N;
  for (int i = 0; i < N; i++) {
    std::cin >> S[i];
  }
  mergesort(S, 0, N);
  for (int i = 0; i < N; i++) {
    if (i == N - 1) {
      std::cout << S[i] << std::endl;
    } else {
      std::cout << S[i] << " ";
    }
  }
  std::cout << cnt << std::endl;
  return 0;
}