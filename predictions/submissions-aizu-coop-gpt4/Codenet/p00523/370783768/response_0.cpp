#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
const int64 INF = 1LL << 58;
int N;
vector<int> A(200000);
vector<int64> sum(200000);

bool Find(const int &pos, const int64 &size) {
  auto hoge = lower_bound(sum.begin() + pos + 1, sum.begin() + N + pos + 1, sum[pos] + size);
  if (hoge == sum.begin() + N + pos + 1)
    return false;
  auto fuga = lower_bound(hoge + 1, sum.begin() + N + pos + 1, *hoge + size);
  if (fuga == sum.begin() + N + pos + 1)
    return false;
  auto foo = lower_bound(fuga + 1, sum.begin() + N + pos + 1, *fuga + size);
  return (foo != sum.begin() + N + pos + 1);
}

bool calc(int64 size) {
  for (int pos = 0; pos < N; pos++) {
    if (Find(pos, size))
      return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
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
  return 0;
}