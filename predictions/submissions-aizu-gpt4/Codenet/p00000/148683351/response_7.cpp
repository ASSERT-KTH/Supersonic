#include <iostream>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  
  int result[10][10];
  for (int i = 1; i <= 9; ++i) {
    for (int j = 1; j <= 9; ++j) {
      result[i][j] = i * j;
    }
  }
  
  for (int i = 1; i <= 9; ++i) {
    for (int j = 1; j <= 9; ++j) {
      cout << i << "x" << j << "=" << result[i][j] << '\n';
    }
  }
  return 0;
}