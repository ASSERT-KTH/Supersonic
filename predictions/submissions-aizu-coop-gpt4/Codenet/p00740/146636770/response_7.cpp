#include <iostream>
#include <algorithm> // for std::fill

using namespace std;

int main(void) {
  int stone[50];
  std::fill(stone, stone+50, 0); // Fill the 'stone' array with zeros once

  while (1) {
    int bowl, n, p;
    cin >> n >> p;

    if (n == 0 && p == 0) {
      return 0; // Program termination condition
    }

    bowl = p;
    int ans;

    for (int i = 0;; i = (i + 1) % n) {
      if (bowl == 0) {
        bowl = bowl + stone[i];
        stone[i] = 0;
      } else {
        stone[i]++;
        bowl--;
        if (bowl == 0 && stone[i] == p) {
          ans = i;
          break; // Break the loop when the desired condition is met
        }
      }
    }
    cout << ans << endl;
  }
}