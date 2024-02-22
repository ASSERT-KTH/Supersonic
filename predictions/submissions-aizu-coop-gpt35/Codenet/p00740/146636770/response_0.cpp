#include <iostream>
using namespace std;

int main(void) {
  int stone[50];
  
  while (true) {
    for (int k = 0; k < 50; k++) {
      stone[k] = 0;
    }
    
    int n, p;
    cin >> n >> p;

    if (n == 0 && p == 0) {
      return 0;
    }

    int ans = 0;
    int bowl = p;
    bool flg = true;

    while (flg) {
      if (bowl == 0) {
        bowl = bowl + stone[ans];
        stone[ans] = 0;
      } else {
        stone[ans]++;
        bowl--;

        if (bowl == 0 && stone[ans] == p) {
          flg = false;
        }
      }

      ans = (ans + 1) % n;
    }

    cout << ans << endl;
  }
}