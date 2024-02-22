#include <iostream>
using namespace std;

int main(void) {
  while (1) {
    int stone[50];  // Move the stone array outside the loop to avoid unnecessary allocation
    int bowl;
    int n, p;
    cin >> n;
    cin >> p;
    if (n == 0 && p == 0) {
      return 0;
    }
    bowl = p;
    int ans;
    int nextIndex = 0;  // Use a separate variable to keep track of the next index

    for (int i = 0; ; i = nextIndex) {  // Remove the modulo operation from the loop condition
      if (bowl == 0) {
        bowl = bowl + stone[i];
        stone[i] = 0;
      } else {
        stone[i]++;
        bowl--;
        if (bowl == 0 && stone[i] == p) {
          ans = i;
          break;  // Use a break statement to exit the loop immediately
        }
      }
      nextIndex = (i + 1) % n;  // Update the next index separately
    }

    cout << ans << endl;
  }
}