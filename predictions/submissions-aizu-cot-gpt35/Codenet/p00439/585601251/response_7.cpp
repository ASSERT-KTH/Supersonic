#include <iostream>
#include <vector>

int main() {
  int n, k;
  while (true) {
    std::cin >> n >> k;
    if (n == 0) break;
    
    std::vector<long long> ac(n + 1);
    ac[0] = 0;
    for (int i = 1; i <= n; ++i) {
      std::cin >> ac[i];
      ac[i] += ac[i - 1];
    }
    
    long long res = -9223372036854775807LL; // LLONG_MIN
    for (int i = k; i <= n; ++i) {
      if (ac[i] - ac[i - k] > res) {
        res = ac[i] - ac[i - k];
      }
    }
    
    std::cout << res << std::endl;
  }
  
  return 0;
}