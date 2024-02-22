#include <cstdio>
#include <map>

int main() {
  int n;
  std::scanf("%d", &n);
  int min = 2000000, t;
  std::map<int, int> A;
  for (int i = 0; i < n; ++i) {
    std::scanf("%d", &t);
    if (t < min)
      min = t;
    A[t]++;
  }
  A[min]--;
  std::printf("%d", min);
  for (auto it = A.begin(); it != A.end(); ++it) {
    for(int i = 0; i < it->second; ++i) {
      std::printf(" %d", it->first);
    }
  }
  std::printf("\n");
  return 0;
}