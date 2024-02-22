#include <iostream>
#include <algorithm>
using namespace std;

const long long INF = 1LL << 58;
int N, A[200000];
long long sum[200000];

bool calc(long long size) {
  int start = 0, end = N;
  while (start < end) {
    int mid = (start + end) / 2;
    if (sum[mid] - sum[0] >= size)
      end = mid;
    else
      start = mid + 1;
  }
  return (sum[end] - sum[0] >= size);
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    A[N + i] = A[i];
  }
  sum[0] = A[0];
  for (int i = 1; i < 2 * N; i++) {
    sum[i] = sum[i - 1] + A[i];
  }
  long long low = 0, high = INF;
  while (high != low) {
    long long mid = (low + high + 1) / 2;
    if (calc(mid))
      low = mid;
    else
      high = mid - 1;
  }
  cout << low << endl;
  return 0;
}