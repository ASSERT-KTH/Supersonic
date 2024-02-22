#include <iostream>
using namespace std;

int main(void) {
  int stone[50];
  int ans; // Removed unnecessary initialization
  while (1) {
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
    for (int i = 0; ; i = (i + 1) % n) { // Removed unnecessary variable and condition
      if (bowl == 0) {
        bowl = bowl + stone[i];
        stone[i] = 0;
      } else {
        stone[i]++;
        bowl--;
        if (bowl == 0 && stone[i] == p) {
          ans = i;
          break; // Removed unnecessary variable
        }
      }
    }
    cout << ans << endl;
  }
}