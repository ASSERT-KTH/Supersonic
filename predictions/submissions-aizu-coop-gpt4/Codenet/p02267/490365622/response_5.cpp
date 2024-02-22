#include <iostream>
#include <unordered_map>

int main() {
  int n, q, tmp, cnt = 0;
  std::unordered_map<int, bool> S;
  
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> tmp;
    S[tmp] = true;
  }
  
  std::cin >> q;
  for (int j = 0; j < q; j++) {
    std::cin >> tmp;
    if (S.find(tmp) != S.end()) {
      cnt++;
    }
  }
  
  std::cout << cnt << std::endl;
  
  return 0;
}