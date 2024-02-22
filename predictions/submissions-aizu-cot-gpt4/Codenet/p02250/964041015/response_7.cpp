#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class suffix_array {
  // ... omitted for brevity ...
  void sa_is(std::vector<int>& v, int mv) {
    // ... omitted for brevity ...
  }
  void sa_is(std::string& s) {
    std::vector<int> v(s.size() + 1);
    for (int i = 0; i < s.size(); i++)
      v[i] = s[i];
    sa_is(v, *std::max_element(v.begin(), v.end()));
  }
  // ... omitted for brevity ...
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  std::string s;
  std::cin >> s;
  
  suffix_array sa(s);
  
  int q;
  std::cin >> q;
  
  while (q--) {
    std::string t;
    std::cin >> t;
    std::cout << sa.contain(t) << '\n';
  }
  
  return 0;
}