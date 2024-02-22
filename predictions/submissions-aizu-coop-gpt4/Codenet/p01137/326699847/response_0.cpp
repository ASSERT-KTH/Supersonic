#include <iostream>
#include <algorithm>
using namespace std;

// Store all square and cube numbers up to 100
int square[101], cube[101];

int main(void) {
  // Precompute square and cube numbers
  for (int i = 0; i <= 100; ++i) {
    square[i] = i * i;
    cube[i] = i * i * i;
  }

  int e;
  while (cin >> e, e) {
    int m = 1000000;
    for (int z = 100; z >= 0; --z) {
      if (cube[z] > e)
        continue;
      for (int y = 100; y >= 0; --y) {
        int val = cube[z] + square[y];
        if (val > e)
          break;
        m = min(m, (e - val) + y + z);
      }
    }
    cout << m << endl;
  }
  return EXIT_SUCCESS;
}