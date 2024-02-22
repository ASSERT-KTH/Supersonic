#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
const int64 INF = 1LL << 58;
int N, A[200000];
int64 sum[200000];

bool Find(const int &pos, const int64 &size) {
  int hoge = lower_bound(sum + pos + 1, sum + N, sum[pos] + size) - sum;
  if (hoge == N)
    return false;
  int fuga = hoge + 1;
  while(fuga < N && sum[fuga] - sum[hoge] < size) fuga++;
  if (fuga == N)
    return false;
  int foo = fuga + 1;
  while(foo < N && sum[foo] - sum[fuga] < size) foo++;
  return (foo != N);
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
  }
  sum[0] = A[0];
  for (int i = 1; i < N; i++) {
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
  cout << low << "\n";
}