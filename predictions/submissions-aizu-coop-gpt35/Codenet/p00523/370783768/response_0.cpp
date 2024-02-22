#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
const int64 INF = 1LL << 58;

bool calc(int N, int* A, int64 size) {
  int64 subarray_sum = 0;
  int start = 0, end = 0;
  
  while (end < 2 * N) {
    subarray_sum += A[end];
    
    if (end >= N) {
      subarray_sum -= A[start];
      start++;
    }
    
    if (subarray_sum >= size)
      return true;
    
    end++;
  }
  
  return false;
}

int main() {
  int N;
  scanf("%d", &N);
  
  int A[200000];
  for (int i = 0; i < N; i++) {
    scanf("%d", A + i);
    A[N + i] = A[i];
  }
  
  int64 low = 0, high = INF;
  
  #pragma GCC optimize("O3")
  while (high != low) {
    int64 mid = (low + high + 1) >> 1;
    
    if (calc(N, A, mid))
      low = mid;
    else
      high = mid - 1;
  }
  
  printf("%lld\n", low);
}