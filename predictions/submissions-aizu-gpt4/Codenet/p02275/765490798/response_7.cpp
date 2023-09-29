#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

void counting_sort(std::vector<int>& v) {
  int max = *std::max_element(v.begin(), v.end());
  std::vector<int> count(max + 1, 0);
  for(auto val : v)
    count[val]++;
  v.clear();
  for(int i = 0; i <= max; ++i)
    for(int j = 0; j < count[i]; ++j)
      v.push_back(i);
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> A(n);
  for(int& a : A) 
    std::cin >> a;
  counting_sort(A);
  std::copy(A.begin(), A.end(), std::ostream_iterator<int>(std::cout, " "));
  return 0;
}