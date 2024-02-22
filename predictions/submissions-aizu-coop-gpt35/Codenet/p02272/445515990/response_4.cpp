#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
const int INF = 1000000001;
const int MAX = 500000;
int cnt;
int S[MAX] = {0};

void merge(int *A, int left, int mid, int right) {
  int n1, n2, n, i, j;
  n1 = mid - left;
  n2 = right - mid;
  
  int L[n1], R[n2];

  for (int i = 0; i < n1; i++) {
    L[i] = A[left + i];
  }
  for (int i = 0; i < n2; i++) {
    R[i] = A[mid + i];
  }
  
  i = 0;
  j = 0;
  int k = left;
  
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      A[k++] = L[i++];
    } else {
      A[k++] = R[j++];
    }
    cnt++;
  }
  
  while (i < n1) {
    A[k++] = L[i++];
    cnt++;
  }
  
  while (j < n2) {
    A[k++] = R[j++];
    cnt++;
  }
}

void mergesort(int *A, int left, int right) {
  int mid;
  int stack[MAX];

  int top = -1;
  
  stack[++top] = left;
  stack[++top] = right;
  
  while (top >= 0) {
    right = stack[top--];
    left = stack[top--];
    
    if (left + 1 < right) {
      mid = (left + right) / 2;
      
      stack[++top] = left;
      stack[++top] = mid;
      
      stack[++top] = mid;
      stack[++top] = right;
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