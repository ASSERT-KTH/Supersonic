#include <iostream>
using namespace std;
int main(void) {
  int stone[50] = {0};
  int bowl, n, p, ans;
  bool flg;
  while (cin >> n >> p, n || p) {
    bowl = p;
    flg = true;
    fill(stone, stone + n, 0);
    for (int i = 0; flg; i = (i + 1) % n) {
      if (!bowl) {
        bowl = stone[i];
        stone[i] = 0;
      } else {
        stone[i]++;
        bowl--;
        if (!bowl && stone[i] == p) {
          ans = i;
          flg = false;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}