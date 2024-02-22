#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  int z;  // Change data type to int as the input constraint is not mentioned
  while (cin >> z && z) {
    int ans = 0;  // Change data type to int
    int z_cubed = z * z * z;  // Store z * z * z in a variable for reuse
    int x_cubed_max = cbrt(z_cubed);  // Calculate the maximum value of x in the loop bound
    int y_cubed_max = cbrt(z_cubed - x_cubed_max * x_cubed_max * x_cubed_max);  // Calculate the maximum value of y in the loop bound
    for (int x = 1; x <= x_cubed_max; x++) {
      int x_cubed = x * x * x;  // Store x * x * x in a variable for reuse
      for (int y = 1; y <= y_cubed_max; y++) {
        int y_cubed = y * y * y;  // Store y * y * y in a variable for reuse
        int sum = x_cubed + y_cubed;
        if (sum <= z_cubed) {
          ans = max(ans, sum);
        } else {
          break;  // No need to continue the loop if sum > z_cubed
        }
      }
    }
    cout << z_cubed - ans << endl;
  }
}