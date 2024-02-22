#include <iostream>
using namespace std;

int main(void) {
  int stone[50];
  while (1) {
    for (int k = 0; k < 50; k++) {
      stone[k] = 0;
    }
    int bowl, n, p;
    cin >> n >> p;
    if (n == 0 && p == 0) {
      return 0;
    }
    bowl = p;
    int ans;
    for (int i = 0; bowl != 0 || stone[i] != p; i = (i + 1) % n) {
      if (bowl == 0) {
        bowl = bowl + stone[i];
        stone[i] = 0;
      } else {
        stone[i]++;
        bowl--;
        if (bowl == 0 && stone[i] == p) {
          ans = i;
        }
      }
    }
    cout << ans << endl;
  }
}