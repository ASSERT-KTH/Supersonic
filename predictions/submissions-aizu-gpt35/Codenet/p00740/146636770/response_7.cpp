#include <iostream>
using namespace std;
int main(void) {
  int stone[50];
  for (int k = 0; k < 50; k++) {
    stone[k] = 0;
  }
  int bowl, n, p;
  while (cin >> n >> p && (n || p)) {
    bowl = p;
    bool flg = true;
    int ans, i = 0;
    while (flg) {
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
      i = (i + 1) % n;
    }
    cout << ans << endl;
  }
}