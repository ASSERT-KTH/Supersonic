#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
const int64 INF = 1LL << 58;

bool isSubarraySumPossible(const int &pos, const int64 &size, const vector<int>& A) {
  int N = A.size();
  int64 currentSum = 0;
  for (int i = pos; i < N + pos; i++) {
    currentSum += A[i % N];
    if (currentSum >= size) {
      return true;
    }
    if (currentSum < 0) {
      currentSum = 0;
    }
  }
  return false;
}

bool calc(int64 size, const vector<int>& A) {
  int N = A.size();
  for (int pos = 0; pos < N; pos++) {
    if (isSubarraySumPossible(pos, size, A)) {
      return true;
    }
  }
  return false;
}

int main() {
  int N;
  scanf("%d", &N);
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
    A.push_back(A[i]);
  }

  int64 low = 0, high = INF;
  while (high != low) {
    int64 mid = (low + high + 1) >> 1;
    if (calc(mid, A)) {
      low = mid;
    } else {
      high = mid - 1;
    }
  }
  printf("%lld\n", low);
}