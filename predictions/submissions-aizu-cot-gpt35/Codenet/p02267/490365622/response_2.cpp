#include <iostream>
#include <unordered_set>
#include <vector>

int main() {
  int n, q;
  std::cin >> n;
  
  std::unordered_set<int> S;
  for (int i = 0; i < n; i++) {
    int num;
    std::cin >> num;
    S.insert(num);
  }
  
  std::cin >> q;
  
  int cnt = 0;
  for (int j = 0; j < q; j++) {
    int num;
    std::cin >> num;
    if (S.find(num) != S.end()) {
      cnt++;
    }
  }
  
  std::cout << cnt << std::endl;
  
  return 0;
}