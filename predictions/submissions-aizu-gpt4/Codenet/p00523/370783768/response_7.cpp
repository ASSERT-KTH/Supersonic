#include <vector>
#include <algorithm>
using namespace std;
typedef long long int64;
const int64 INF = 1LL << 58;
int64 sum[400000];
int main() {
  int N;
  scanf("%d", &N);
  vector<int64> A(2*N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &A[i]);
    A[N + i] = A[i];
  }
  sum[0] = A[0];
  for (int i = 1; i < 2 * N; i++) {
    sum[i] = sum[i - 1] + A[i];
  }
  int64 low = 0, high = INF;
  while (high != low) {
    int64 mid = (low + high + 1) >> 1;
    bool found = false;
    for (int i = 0; i < N && !found; i++) {
      auto it = lower_bound(sum + i + 1, sum + N + i + 1, sum[i] + mid);
      if (it != sum + N + i + 1) {
        it = lower_bound(it + 1, sum + N + i + 1, *it + mid);
        if (it != sum + N + i + 1) {
          it = lower_bound(it + 1, sum + N + i + 1, *it + mid);
          if (it != sum + N + i + 1)
            found = true;
        }
      }
    }
    if (found)
      low = mid;
    else
      high = mid - 1;
  }
  printf("%lld\n", low);
}