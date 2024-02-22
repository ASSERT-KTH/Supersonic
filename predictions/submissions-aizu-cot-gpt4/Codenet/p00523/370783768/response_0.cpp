#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int64;
const int64 INF = 1LL << 58;

vector<int> A;
vector<int64> sum;

bool Find(int64 size, int N) {
  int l = 0, r = 0;
  int64 current_sum = 0;
  while (l < N) {
    while (r < N * 2 && current_sum < size) {
      current_sum += A[r % N];
      r++;
    }
    if (current_sum == size) return true;
    current_sum -= A[l];
    l++;
  }
  return false;
}

int main() {
  int N;
  cin >> N;
  A.resize(N);
  sum.resize(N * 2);

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sum[0] = A[0];
  for (int i = 1; i < 2 * N; i++) {
    sum[i] = sum[i - 1] + A[i % N];
  }
  int64 low = 0, high = INF;
  while (high != low) {
    int64 mid = (low + high + 1) >> 1;
    if (Find(mid, N))
      low = mid;
    else
      high = mid - 1;
  }
  cout << low << endl;
}