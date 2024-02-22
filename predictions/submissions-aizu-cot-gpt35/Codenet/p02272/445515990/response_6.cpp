#include <iostream>
using namespace std;

const int INF = 1000000001;
const int MAX = 500000;

int cnt;
int S[MAX] = {0}, L[1 + MAX / 2] = {0}, R[1 + MAX / 2] = {0};

void merge(int& A, int left, int mid, int right) {
  auto itL = A + left;
  auto itR = A + mid;
  auto itEnd = A + right;

  auto itOut = L;
  while (itL != itR && itR != itEnd) {
    *itOut++ = (*itL <= *itR) ? *itL++ : *itR++;
    cnt++;
  }
  
  while (itL != itR) {
    *itOut++ = *itL++;
    cnt++;
  }
  
  while (itR != itEnd) {
    *itOut++ = *itR++;
    cnt++;
  }

  copy(L, itOut, A + left);
}

void mergesort(int& A, int left, int right) {
  if (left + 1 < right) {
    int mid = left + (right - left) / 2;
    mergesort(A, left, mid);
    mergesort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main() {
  int N;
  cin >> N;

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