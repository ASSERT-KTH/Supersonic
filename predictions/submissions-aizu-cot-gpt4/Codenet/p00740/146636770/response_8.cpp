#include <iostream>
#include <cstring>
using namespace std;

int main(void) {
  int stone[50];
  
  while (1) {
    memset(stone, 0, sizeof(stone));
    
    int n, p;
    cin >> n >> p;
    if (n == 0 && p == 0) {
      return 0;
    }
    
    int bowl = p;
    int ans;
    
    for (int i = 0; ; i = (i + 1) % n) {
      if (bowl == 0) {
        bowl = bowl + stone[i];
        stone[i] = 0;
      } else {
        stone[i]++;
        bowl--;
        if (bowl == 0 && stone[i] == p) {
          ans = i;
          break;
        }
      }
    }
    
    cout << ans << endl;
  }
}