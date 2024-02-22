#include <iostream>
using namespace std;

int main(void) {
  while (1) {
    int n, p;
    cin >> n;
    cin >> p;
    if (n == 0 && p == 0) {
      return 0;
    }
    int* stone = new int[n]; // Dynamically allocate the stone array
    for (int k = 0; k < n; k++) {
      stone[k] = 0;
    }
    int bowl = p;
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
    delete[] stone; // Deallocate the dynamically allocated stone array
    cout << ans << endl;
  }
}