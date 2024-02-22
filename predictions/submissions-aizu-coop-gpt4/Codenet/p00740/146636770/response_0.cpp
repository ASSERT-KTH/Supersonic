#include <iostream>
#include <algorithm>  // for std::fill_n
using namespace std;

int main(void) {
  while (true) {
    int n, p;
    cin >> n >> p;
    if (n == 0 && p == 0) {
      return 0;
    }

    int stone[n];
    std::fill_n(stone, n, 0);
    int bowl = p;
    int ans;

    for (int i = 0; ; i = (i + 1) % n) {
      if (bowl == 0) {
        bowl += stone[i];
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