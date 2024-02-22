#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); //Optimize I/O operations
  cin.tie(NULL); //Untie cin from cout

  int n;
  cin >> n;
  int value;
  cin >> value;

  int max_diff = -2000000000; // Initialize to very small value
  int min_value = value;

  for (int i = 1; i < n; i++) { // Start from 1 as we've already read the first value
    cin >> value;
    max_diff = max(max_diff, value - min_value);
    min_value = min(min_value, value);
  }

  cout << max_diff << "\n"; //Use \n instead of endl to avoid unnecessary flush

  return 0;
}