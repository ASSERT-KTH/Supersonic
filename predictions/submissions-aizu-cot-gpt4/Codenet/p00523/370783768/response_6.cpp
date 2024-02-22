#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
const int64 INF = 1LL << 58;
int N;
int64 A[200000];
int64 sum[400000];
bool calc(int64 size) {
  for (int pos = 0; pos < N; pos++) {
    int64 target = sum[pos] + size;
    auto it = lower_bound(sum + pos + 1, sum + 2 * N, target);
    if (it == sum + 2 * N) continue;
    target = *it + size;
    it = lower_bound(it + 1, sum + 2 * N, target);
    if (it == sum + 2 * N) continue;
    target = *it + size;
    it = lower_bound(it + 1, sum + 2 * N, target);
    if (it != sum + 2 * N) return true;
  }
  return false;
}
int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    sum[i + N] = sum[i] = (i == 0 ? 0 : sum[i - 1]) + A[i];
  }
  for (int i = N; i < 2 * N; i++) {
    sum[i] = sum[i - 1] + A[i - N];
  }
  int64 low = 0, high = INF;
  while (high != low) {
    int64 mid = (low + high + 1) >> 1;
    if (calc(mid))
      low = mid;
    else
      high = mid - 1;
  }
  cout << low << "\n";
}