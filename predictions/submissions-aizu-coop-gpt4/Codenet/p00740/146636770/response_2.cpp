#include <iostream>
using namespace std;
int main(void) {
  int n, p;
  while (cin >> n >> p && (n != 0 || p != 0)) {
    int stone[50] = {0};
    int bowl = p;
    bool flg = true;
    int ans;
    for (int i = 0; flg; i = (i + 1) % n) {
      if (bowl == 0) {
        bowl += stone[i];
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
    cout << ans << endl;
  }
  return 0;
}