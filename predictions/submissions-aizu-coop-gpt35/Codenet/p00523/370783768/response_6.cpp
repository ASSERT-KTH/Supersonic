#include <cstdio>
#include <vector>
using namespace std;
typedef long long int64;
const int64 INF = 1LL << 58;

bool Find(const vector<int64>& sum, const int& pos, const int64& size) {
  int hoge = distance(
      sum.begin(), lower_bound(sum.begin() + pos + 1, sum.end(), sum[pos] + size));
  if (hoge == sum.size())
    return false;
  int fuga = distance(
      sum.begin(), lower_bound(sum.begin() + hoge + 1, sum.end(), sum[hoge] + size));
  if (fuga == sum.size())
    return false;
  int foo = distance(
      sum.begin(), lower_bound(sum.begin() + fuga + 1, sum.end(), sum[fuga] + size));
  return (foo != sum.size());
}

bool calc(const vector<int>& A, int64 size) {
  int N = A.size() / 2;
  vector<int64> sum(2 * N);
  sum[0] = A[0];
  for (int i = 1; i < 2 * N; i++) {
    sum[i] = sum[i - 1] + A[i];
  }
  for (int pos = 0; pos < N; pos++) {
    if (Find(sum, pos, size))
      return true;
  }
  return false;
}

int main() {
  int N;
  scanf("%d", &N);
  vector<int> A(2 * N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
    A[N + i] = A[i];
  }

  int64 low = 0, high = INF;
  while (high != low) {
    int64 mid = (low + high + 1) >> 1;
    if (calc(A, mid))
      low = mid;
    else
      high = mid - 1;
  }
  printf("%lld\n", low);

  return 0;
}