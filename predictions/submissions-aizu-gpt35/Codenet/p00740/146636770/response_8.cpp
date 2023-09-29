#include <iostream>
using namespace std;
int main(void) {
  int stone[50];
  for (int k = 0; k < 50; k++) {
    stone[k] = 0;
  }
  int bowl;
  int n, p;
  while (cin >> n >> p && (n || p)) {
    bowl = p;
    int ans = -1;
    for (int i = 0, count = n; count > 0; i = (i + 1) % n) {
      if (bowl == 0) {
        bowl = stone[i];
        stone[i] = 0;
      } else {
        stone[i]++;
        bowl--;
        if (bowl == 0 && stone[i] == p) {
          ans = i;
          count--;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}