#include <iostream>
#include <vector>
#include <algorithm>
typedef long long int64;
const int64 INF = 1LL<<58;
int N;
std::vector<int64> sum(200000);

bool Find(const int &pos, const int64 &size) {
  int limit = N + pos + 1;
  int hoge = std::distance(sum.begin(), std::lower_bound(sum.begin() + pos + 1, sum.begin() + limit, sum[pos] + size));
  if (hoge == limit)
    return false;
  int fuga = std::distance(sum.begin(), std::lower_bound(sum.begin() + hoge + 1, sum.begin() + limit, sum[hoge] + size));
  if (fuga == limit)
    return false;
  int foo = std::distance(sum.begin(), std::lower_bound(sum.begin() + fuga + 1, sum.begin() + limit, sum[fuga] + size));
  return (foo != limit);
}

bool calc(int64 size) {
  for (int pos = 0; pos < N; pos++) {
    if (Find(pos, size))
      return true;
  }
  return false;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  std::cin>>N;
  std::vector<int> A(2*N);
  for (int i = 0; i < N; i++) {
    std::cin>>A[i];
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
  std::cout<<low<<"\n";
}