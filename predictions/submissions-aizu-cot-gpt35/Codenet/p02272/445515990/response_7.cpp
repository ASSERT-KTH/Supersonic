#include <iostream>
using namespace std;

const int MAX = 500000;

void merge(int *A, int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  int L[n1], R[n2];
  for (int i = 0; i < n1; i++) {
    L[i] = A[left + i];
  }
  for (int i = 0; i < n2; i++) {
    R[i] = A[mid + i];
  }
  int i = 0;
  int j = 0;
  for (int k = left; k < right; k++) {
    if (i < n1 && (j >= n2 || L[i] <= R[j])) {
      A[k] = L[i++];
    } else {
      A[k] = R[j++];
    }
  }
}

void mergesort(int *A, int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    if (right - left < 10) {
      // Use insertion sort for small arrays
      for (int i = left + 1; i < right; i++) {
        int key = A[i];
        int j = i - 1;
        while (j >= left && A[j] > key) {
          A[j + 1] = A[j];
          j--;
        }
        A[j + 1] = key;
      }
    } else {
      mergesort(A, left, mid);
      mergesort(A, mid, right);
      merge(A, left, mid, right);
    }
  }
}

int main() {
  int N;
  cin >> N;
  int S[MAX];
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
  return 0;
}