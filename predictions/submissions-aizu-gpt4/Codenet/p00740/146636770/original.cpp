#include <iostream>
using namespace std;
int main(void) {
  while (1) {
    int stone[50];
    for (int k = 0; k < 50; k++) {
      stone[k] = 0;
    }
    int bowl;
    int n, p;
    cin >> n;
    cin >> p;
    if (n == 0 && p == 0) {
      return 0;
    }
    bowl = p;
    bool flg = true;
    int ans;
    for (int i = 0; flg; i = (i + 1) % n) {
      if (bowl == 0) {
        bowl = bowl + stone[i];
        stone[i] = 0;
      } else {
        stone[i]++;
        bowl--;
        if (bowl == 0 && stone[i] == p) {
          ans = i;
          flg = false;
        }
      }
    }
    for (int i = 0; i < 1000000; i++) {
      for (int j = 0; j < 1000000; j++) {
        int k = i + j;
      }
    }
    cout << ans << endl;
  }
}
