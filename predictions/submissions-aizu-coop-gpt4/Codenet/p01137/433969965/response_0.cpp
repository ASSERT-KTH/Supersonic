#include <bits/stdc++.h>
#include <omp.h> // Include OpenMP library
using namespace std;
const int inf = 1000000000;

int main() {
  ios_base::sync_with_stdio(false); // Improve IO performance
  cin.tie(NULL);

  int e;
  while (cin >> e, e) {
    int ans = inf;
    for (int z = 0; z * z * z <= e; ++z) {
      int z_cubed = z * z * z; // Compute once at the start of each iteration
      int y_squared = 0; // Initialize y_squared
      #pragma omp parallel for reduction(min : ans) // Parallelize the loop and use reduction for the min operation
      for (int y = 0; y_squared + z_cubed <= e; ++y) {
        int x = e - (y_squared + z_cubed);
        ans = min(ans, x + y + z);
        y_squared += 2 * y + 1; // Increment y_squared
      }
    }
    cout << ans << "\n";
  }
  return 0;
}