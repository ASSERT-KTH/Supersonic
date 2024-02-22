#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int64;
const int64 INF = 1LL << 58;
int N, A[200000];
int64 sum[200000];

bool Find(const int &pos, const int64 &size) {
  int end = N + pos + 1;
  int hoge = distance(sum, lower_bound(sum + pos + 1, sum + end, sum[pos] + size));

  if (hoge == end)
    return false;
  int fuga = distance(sum, lower_bound(sum + hoge + 1, sum + end, sum[hoge] + size));

  if (fuga == end)
    return false;
  int foo = distance(sum, lower_bound(sum + fuga + 1, sum + end, sum[fuga] + size));

  return (foo != end);
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
  cin >> A[0];
  sum[0] = A[0];
  for (int i = 1; i < N; i++) {
    cin >> A[i];
    sum[i] = sum[i - 1] + A[i];
    sum[N + i] = sum[i - 1] + A[N + i];
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