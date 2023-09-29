#include <iostream>
#include <vector>
#include <algorithm>

inline void counting_sort(std::vector<int>& v) {
  int max = *std::max_element(v.begin(), v.end());
  std::vector<int> count(max + 1, 0);
  
  for(auto val : v)
    ++count[val];
  
  int index = 0;
  for(int i = 0; i <= max; ++i)
    for(int j = 0; j < count[i]; ++j)
      v[index++] = i;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  
  int n;
  std::cin >> n;
  std::vector<int> A(n);
  
  for(auto& element : A)
    std::cin >> element;
  
  counting_sort(A);
  
  for(const auto& element : A)
    std::cout << element << ' ';
  
  std::cout << '\n';
  
  return 0;
}