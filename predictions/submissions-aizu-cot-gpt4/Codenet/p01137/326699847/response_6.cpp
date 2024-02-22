#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main(void) {
  int e;
  int val[101];
  int root[1000001];
  for (int i = 0; i <= 100; i++) {
    val[i] = i * i * i;
  }
  for (int i = 0; i <= 1000000; i++) {
    root[i] = sqrt(i);
  }
  while (cin >> e, e) {
    int m = e;
    for (int z = 100; z >= 0; --z) {
      if (val[z] > e)
        continue;
      for (int y = root[e - val[z]]; y >= 0; --y) {
        int val2 = val[z] + y * y;
        if (val2 > e)
          continue;
        m = min(m, (e - val2) + y + z);
      }
    }
    cout << m << endl;
  }
  return 0;
}