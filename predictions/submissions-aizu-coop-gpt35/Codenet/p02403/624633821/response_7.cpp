#include <iostream>

int main() {
  int a = 0;
  
  while (true) {
    int height, width;
    std::cin >> height >> width;
    
    if (height == 0 && width == 0)
      break;
    
    for (int i = 0; i < height; i++) {
      std::string line(width, '#');
      std::cout << line << '\n';
    }
    
    std::cout << '\n';
    
    a++;
  }
  
  return 0;
}