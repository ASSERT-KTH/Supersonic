#include <iostream>
typedef long long int64;

int N, A[200000];

bool Find(const int &pos, const int64 &size) {
  int hoge = std::distance(
      A + pos, std::lower_bound(A + pos, A + N + pos, A[pos] + size));
  if (hoge == N + pos)
    return false;
  int foo = std::distance(
      A + hoge, std::lower_bound(A + hoge, A + N + pos, A[hoge] + size));
  return (foo != N + pos);
}

bool calc(int64 size) {
  for (int pos = 0; pos < N; pos++) {
    if (Find(pos, size))
      return true;
  }
  return false;
}

int main() {
  std::cin >> N;
  for (int i = 0; i < N; i++) {
    std::cin >> A[i];
    A[N + i] = A[i];
  }

  int64 low = 0, high = 1LL << 58;
  while (low < high) {
    int64 mid = (low + high + 1) >> 1;
    if (calc(mid))
      low = mid;
    else
      high = mid - 1;
  }
  
  std::cout << low << std::endl;
}