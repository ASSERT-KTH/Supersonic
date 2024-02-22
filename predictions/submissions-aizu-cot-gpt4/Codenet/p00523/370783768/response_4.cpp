#include <iostream>
#include <algorithm>

using namespace std;
typedef long long int64;
const int64 INF = 1LL << 58;
int N, A[100000];
int64 sum[200000];

bool Find(int pos, int64 size) {
  auto hoge = lower_bound(sum + pos + 1, sum + N + pos + 1, sum[pos] + size);
  if (hoge == sum + N + pos + 1)
    return false;
  auto fuga = lower_bound(hoge + 1, sum + N + pos + 1, *hoge + size);
  if (fuga == sum + N + pos + 1)
    return false;
  auto foo = lower_bound(fuga + 1, sum + N + pos + 1, *fuga + size);
  return (foo != sum + N + pos + 1);
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
    if (i == 0)
      sum[i] = A[i];
    else
      sum[i] = sum[i - 1] + A[i];
    sum[i + N] = sum[i];
  }
  int64 low = 0, high = INF;
  while (high != low) {
    int64 mid = (low + high + 1) >> 1;
    if (calc(mid))
      low = mid;
    else
      high = mid - 1;
  }
  cout << low << endl;
  return 0;
}