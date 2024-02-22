#include <iostream>

int main() {
  while (true) {
    int n, m, a;
    std::cin >> n >> m >> a;
    if (n == 0 && m == 0 && a == 0) {
      break;
    }
    
    int amida[101][1001] = {{0}};
    
    for (int i = 0; i < m; i++) {
      int h, p, q;
      std::cin >> h >> p >> q;
      amida[p][h] = 1;
    }
    
    for (int j = 1000; j > 0; j--) {
      if (amida[a][j] == 1)
        ++a;
      else if (amida[a - 1][j] == 1)
        --a;
      
      if (a == 0) {
        break;
      }
    }
    
    std::cout << a << std::endl;
  }
  
  return 0;
}