#include <iostream>
#include <cstring>
#include <algorithm>

const long long INF = 1LL << 30;
const int MAX_N = 200000;

int N, A[MAX_N];
long long sum[2 * MAX_N];

bool Find(int pos, long long size) {
  auto it1 = std::lower_bound(sum + pos + 1, sum + N + pos + 1, sum[pos] + size);
  if (it1 == sum + N + pos + 1)
    return false;
  auto it2 = std::lower_bound(it1 + 1, sum + N + pos + 1, *it1 + size);
  if (it2 == sum + N + pos + 1)
    return false;
  auto it3 = std::lower_bound(it2 + 1, sum + N + pos + 1, *it2 + size);
  return (it3 != sum + N + pos + 1);
}

bool calc(long long size) {
  for (int pos = 0; pos < N; pos++) {
    if (Find(pos, size))
      return true;
  }
  return false;
}

int main() {
  std::cin >> N;
  for (int i = 0; i < N; i++) {
    std::cin >> A[i];
    A[N + i] = A[i];
  }
  
  memset(sum, 0, sizeof(sum));
  for (int i = 1; i < 2 * N; i++) {
    sum[i] = sum[i - 1] + A[i];
  }
  
  long long low = 0, high = INF;
  while (high != low) {
    long long mid = (low + high + 1) >> 1;
    if (calc(mid))
      low = mid;
    else
      high = mid - 1;
  }
  
  std::cout << low << std::endl;
  
  return 0;
}