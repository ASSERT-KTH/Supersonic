#include <cstdio>
#include <string>
using namespace std;

const int MAX = 500000;
int cnt;
int S[MAX] = {0};

void merge(int *A, int left, int mid, int right) {
  int i = left, j = mid;
  while (i < mid && j < right) {
    if (A[i] <= A[j]) {
      i++;
    } else {
      swap(A[i], A[j]);
      j++;
    }
    cnt++;
  }
}

void mergesort(int *A, int left, int right) {
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
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &S[i]);
  }
  mergesort(S, 0, N);
  string output;
  for (int i = 0; i < N-1; i++) {
    output += to_string(S[i]) + " ";
  }
  output += to_string(S[N-1]);
  printf("%s\n%d\n", output.c_str(), cnt);
  return 0;
}