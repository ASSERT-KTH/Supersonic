#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int tb[1112], ans[1112], N;
  
  // Pre-compute and store cubes of numbers in tb array
  for (int i = 1; i < 1112; i++) {
    tb[i] = i * i * i;
  }

  // Pre-compute and store the smallest difference in ans array
  for (int z = 1; z < 1112; z++) {
    int z3 = tb[z], ret = z3;

    // Calculate the upper limit for i
    int max_i = cbrt(z3 / 2);
    for (int i = 1; i <= max_i; i++) {
      int i3 = tb[i];

      // Find the greatest cube number less than or equal to z3 - i3
      int j3 = tb[(int)cbrt(z3 - i3)];
      if (i3 + j3 >= z3)
        break;

      ret = min(ret, z3 - i3 - j3);
    }
    ans[z] = ret;
  }

  // Print the smallest difference for each N read from standard input
  while (cin >> N, N) {
    cout << ans[N] << endl;
  }

  return 0;
}