#include <iostream>
using namespace std;

int main(void) {
  int stone[50] = {0}; // Initialize the "stone" array only once
  int bowl;
  int n, p;
  
  while (1) {
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
    cout << ans << endl;
  }
}