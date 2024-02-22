#include <iostream>
using namespace std;
int main(void) {
  while (1) {
    int stone[50];
    int bowl;
    int n, p;
    cin >> n;
    cin >> p;
    if (n == 0 && p == 0) {
      return 0;
    }
    bowl = p;
    int ans;
    for (int i = 0; ; i = (i + 1) % n) {
      if (bowl == 0) {
        bowl = bowl + stone[i];
        stone[i] = 0;
      } else {
        stone[i]++;
        bowl--;
        if (bowl == 0 && stone[i] == p) {
          ans = i;
          break;
        }
      }
    }
    cout << ans << endl;
  }
}