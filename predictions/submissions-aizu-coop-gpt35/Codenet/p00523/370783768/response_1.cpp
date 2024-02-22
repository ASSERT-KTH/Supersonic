#include <iostream>
#include <vector>
using namespace std;
typedef long long int64;
const int64 INF = 1LL << 58;

bool Find(vector<int>::iterator pos, const int64& size, vector<int>::iterator begin, vector<int>::iterator end) {
  auto hoge = lower_bound(pos + 1, end, *pos + size);
  if (hoge == end)
    return false;
  auto fuga = lower_bound(hoge + 1, end, *hoge + size);
  if (fuga == end)
    return false;
  auto foo = lower_bound(fuga + 1, end, *fuga + size);
  return (foo != end);
}

bool calc(const int64& size, vector<int>& sum) {
  for (auto pos = sum.begin(); pos != sum.end(); pos++) {
    if (Find(pos, size, sum.begin(), sum.end()))
      return true;
  }
  return false;
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    A.push_back(A[i]);
  }
  vector<int64> sum(A.size());
  sum[0] = A[0];
  for (int i = 1; i < A.size(); i++) {
    sum[i] = sum[i - 1] + A[i];
  }
  int64 low = 0, high = INF;
  while (high != low) {
    int64 mid = (low + high) >> 1;
    if (calc(mid, sum))
      low = mid + 1;
    else
      high = mid;
  }
  cout << low - 1 << endl;
  return 0;
}