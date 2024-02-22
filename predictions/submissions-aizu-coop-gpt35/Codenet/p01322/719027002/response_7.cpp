#include <iostream>
#include <unordered_map>
#include <array>

int main() {
  std::ios_base::sync_with_stdio(false);
  
  int n, m;
  std::array<int, 100> o;
  std::array<const char*, 100> b;
  std::unordered_map<std::string, int> map;
  std::string l;
  int ans;
  
  for (;;) {
    std::cin >> n >> m;
    if (!n && !m)
      break;
      
    ans = 0;
    for (int i = 0; i < n; i++) {
      std::cin >> l >> o[i];
      b[i] = l.c_str();
      map.emplace(l, o[i]);
    }
    
    for (int i = 0; i < m; i++) {
      std::cin >> l;
      auto it = map.find(l);
      if (it != map.end()) {
        ans += it->second;
      }
    }
    
    std::cout << ans << '\n';
  }
}