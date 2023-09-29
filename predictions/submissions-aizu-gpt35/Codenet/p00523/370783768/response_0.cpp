#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
const int64 INF = 1LL << 58;
const int MAX_N = 200000;
int N, A[MAX_N << 1];
int64 sum[MAX_N << 1], preSum[MAX_N << 1];

bool Find(const int &pos, const int64 &size) {
  int l = pos + 1, r = N + pos + 1;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (sum[mid] - sum[pos] >= size) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  if (r == N + pos + 1)
    return false;
  l = r, r = N + pos + 1;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (sum[mid] - sum[r - 1] >= size) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  if (l == N + pos + 1)
    return false;
  l = r, r = N + pos + 1;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (sum[mid] - sum[r - 1] >= size) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  return true;
}

bool calc(int64 size) {
  for (int pos = 0; pos < N; pos++) {
    if (Find(pos, size))
      return true;
  }
  return false;
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", A + i);
    A[N + i] = A[i];
  }
  partial_sum(A, A + (N << 1), sum);
  int64 low = 0, high = INF;
  while (high != low) {
    int64 mid = (low + high + 1) >> 1;
    if (calc(mid))
      low = mid;
    else
      high = mid - 1;
  }
  printf("%lld\n", low);
}
