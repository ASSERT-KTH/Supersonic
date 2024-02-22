#include <cmath>
#include <iostream>
using namespace std;
int main() {
  double log_factorial = 0.0;
  int i, n;
  cin >> n;
  for (i = 2; i <= n; i += 2) {
    // Unrolling the loop by calculating two terms at a time
    log_factorial += log(i);
    if (i+1 <= n) {
      log_factorial += log(i+1);
    }
  }
  cout << exp(log_factorial) << endl;  // Convert the log factorial back to a regular number
  return 0;
}