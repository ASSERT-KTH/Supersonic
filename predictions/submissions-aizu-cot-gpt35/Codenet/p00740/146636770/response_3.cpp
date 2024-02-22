#include <iostream>
using namespace std;

int main(void) {
  int stone[50] = {0}; // Initialize the stone array outside the loop
  while (1) {
    int n, p;
    cin >> n >> p;
    if (n == 0 && p == 0) {
      return 0;
    }
    int ans = -1;
    int maxStones = 0;
    int bowl = p;
    for (int i = 0; i < n; i++) {
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
      maxStones = max(maxStones, stone[i]); // Keep track of the maximum number of stones
    }
    int totalIterations = maxStones * n; // Determine the total number of iterations based on the maximum number of stones
    for (int i = 0; i < totalIterations; i++) {
      int j = i % n;
      int k = i / n;
    }
    cout << ans << endl;
  }
}