#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long n, a, s;
  while (cin >> n && n != 0) {
    vector<long long> j(n);

    // Calculate the sum and sort the array as we read the input numbers
    s = 0;
    for (int i = 0; i < n; i++) {
      cin >> a;
      s += a;
      j[i] = a;
      if (i > 0) {
        // Insert the current element into the sorted portion of the array
        int jIndex = i;
        while (jIndex > 0 && j[jIndex] < j[jIndex - 1]) {
          swap(j[jIndex], j[jIndex - 1]);
          jIndex--;
        }
      }
    }

    // Calculate the maximum value
    long long maxVal = n * s;
    for (int i = 1; i < n; i++) {
      s += j[i];
      maxVal = max(maxVal, (n - i) * s);
    }

    cout << maxVal << endl;
  }

  return 0;
}