#include <iostream>
using namespace std;

int main() {
  while (true) {
    int n, p;
    cin >> n >> p;
    
    if (n == 0 && p == 0) {
      return 0;
    }
    
    int bowl = p;
    int ans = 0;

    for (int i = 0; bowl > 0; i = (i + 1) % n) {
      if (bowl == 0 && i == 0) {
        ans = n - 1;
        break;
      }

      bowl--;
      if (i == n - 1) {
        bowl += p;
      }
    }

    cout << ans << endl;
  }
}