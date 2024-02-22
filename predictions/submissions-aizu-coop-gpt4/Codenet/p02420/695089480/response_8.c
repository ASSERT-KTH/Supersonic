#include <iostream>
#include <string>
#include <algorithm>

int main() {
  std::string s;
  int m;
  
  // Continue reading until '-' is encountered
  while (std::cin >> s >> m, s[0] != '-') {
    int a = s.length();
    int t = 0;
    
    // Read m numbers and add them to t
    for (int i = 0; i < m; ++i) {
      int h;
      std::cin >> h;
      t += h;
    }
    
    // Rotate the string by t positions
    t %= a; // Reduce t to be less than a
    std::rotate(s.begin(), s.begin() + t, s.end());
    
    // Output the rotated string
    std::cout << s << std::endl;
  }
  
  return 0;
}