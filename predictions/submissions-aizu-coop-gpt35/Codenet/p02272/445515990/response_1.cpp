#include <cstdio>
#include <iostream>
using namespace std;

const int INF = 1000000001;
const int MAX = 500000;

void merge(int *A, int left, int mid, int right, int *temp, int &cnt) {
  int n1 = mid - left;
  int n2 = right - mid;

  int* p1 = &A[left];
  int* p2 = &A[mid];

  for (int* p = temp; p < temp + n1 + n2; ++p) {
    if (p1 == &A[mid]) {
      *p = *p2++;
    } else if (p2 == &A[right]) {
      *p = *p1++;
    } else if (*p1 <= *p2) {
      *p = *p1++;
    } else {
      *p = *p2++;
    }
    cnt++;
  }

  for (int i = 0; i < n1 + n2; ++i) {
    A[left + i] = temp[i];
  }
}

void mergesort(int *A, int left, int right, int *temp, int &cnt) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergesort(A, left, mid, temp, cnt);
    mergesort(A, mid, right, temp, cnt);
    merge(A, left, mid, right, temp, cnt);
  }
}

int main() {
  int N;
  cin >> N;

  int S[MAX];
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }

  int cnt = 0;
  int temp[MAX];
  mergesort(S, 0, N, temp, cnt);

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