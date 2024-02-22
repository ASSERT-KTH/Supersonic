#include <iostream>
#include <set>

int main() {
  std::set<int> data;
  
  for (int i = 0; i < 28; i++) {
    int n;
    std::cin >> n;
    data.insert(n);
  }
  
  for (int i = 1; i <= 30; i++) {
    if (data.find(i) == data.end())
      std::cout << i << std::endl;
  }
}