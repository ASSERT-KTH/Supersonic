#include <iostream>
#include <algorithm>
using namespace std;

using int64 = long long;
const int64 INF = 1LL << 58;
int N, A[200000];
int64 sum[200000];

bool Find(const int &pos, const int64 &size) {
  auto it = lower_bound(sum + pos + 1, sum + N + pos + 1, sum[pos] + size);
  if (it == sum + N + pos + 1)
    return false;
  int index = distance(sum, it);
  it = lower_bound(sum + index + 1, sum + N + pos + 1, sum[index] + size);
  if (it == sum + N + pos + 1)
    return false;
  index = distance(sum, it);
  it = lower_bound(sum + index + 1, sum + N + pos + 1, sum[index] + size);
  return (it != sum + N + pos + 1);
}

bool calc(int64 size) {
  int pos = 0;
  for (int i = 0; i < N; i++) {
    if (i - pos > N)
      return false;
    if (sum[i] - sum[pos] >= size)
      pos++;
    if (Find(i, size))
      return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
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
  while (low < high) {
    int64 mid = (low + high) >> 1;
    if (calc(mid))
      low = mid + 1;
    else
      high = mid;
  }
  
  cout << low << endl;
  return 0;
}