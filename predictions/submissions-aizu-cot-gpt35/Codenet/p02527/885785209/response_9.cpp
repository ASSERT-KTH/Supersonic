#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>

template <typename T>
void quicksort(T begin, T end) {
  if (begin == end) return;
  
  std::random_shuffle(begin, end);
  T pivot = begin;
  std::partition(begin + 1, end, [pivot](const auto& element) {
    return element < *pivot;
  });
  std::swap(*pivot, *(begin + 1));
  
  auto mid = std::partition(begin + 1, end, [pivot](const auto& element) {
    return element <= *pivot;
  });
  std::swap(*pivot, *(mid - 1));
  
  quicksort(begin, mid - 1);
  quicksort(mid, end);
}

int main() {
  std::srand(std::time(nullptr));
  
  int n;
  std::scanf("%d", &n);
  
  std::vector<int> a(n);
  for (int i = 0; i < n; i++)
    std::scanf("%d", &a[i]);
  
  quicksort(a.begin(), a.end());
  
  for (int i = 0; i < n; i++)
    std::printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
  
  return 0;
}