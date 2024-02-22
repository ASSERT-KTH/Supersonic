#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
constexpr int64 INF = 1LL << 58;
int N, A[200000];
int64 sum[200000];
bool Find(const int &pos, const int64 &size) {
  auto first_bound = lower_bound(sum + pos + 1, sum + N + pos + 1, sum[pos] + size);
  if (first_bound == sum + N + pos + 1)
    return false;
  auto second_bound = lower_bound(first_bound + 1, sum + N + pos + 1, *first_bound + size);
  if (second_bound == sum + N + pos + 1)
    return false;
  auto third_bound = lower_bound(second_bound + 1, sum + N + pos + 1, *second_bound + size);
  return (third_bound != sum + N + pos + 1);
}
bool calc(int64 size) {
  for (int pos = 0; pos < N; pos++) {
    if (Find(pos, size))
      return true;
  }
  return false;
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
  int64 low = 0, high = INF;
  while (high != low) {
    int64 mid = (low + high + 1) >> 1;
    if (calc(mid))
      low = mid;
    else
      high = mid - 1;
  }
  cout << low << '\n';
}