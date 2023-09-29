#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
constexpr int INF = 1e9 + 1;
constexpr int MAX = 500000;
int S[MAX] = {0}, L[MAX / 2 + 1], R[MAX / 2 + 1];
int cnt;
inline void merge(int *A, int left, int mid, int right) {
  memcpy(L, A+left, sizeof(int)*(mid-left));
  memcpy(R, A+mid, sizeof(int)*(right-mid));
  L[mid-left] = R[right-mid] = INF;
  for (int i = 0, j = 0, k = left; k < right; k++) {
    cnt++;
    if (L[i] <= R[j]){
      A[k] = L[i++];
    } else {
      A[k] = R[j++];
    }
  }
}
inline void mergesort(int *A, int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergesort(A, left, mid);
    mergesort(A, mid, right);
    merge(A, left, mid, right);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cnt = 0;
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }
  mergesort(S, 0, N);
  for (int i = 0; i < N; i++) {
    cout << S[i];
    if(i != N-1)
       cout << " ";
  }
  cout << "\n" << cnt << "\n";
  return 0;
}