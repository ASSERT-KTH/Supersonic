#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  long long n;
  while (cin >> n && n) { // read size of array and continue till it's not zero
    vector<long long> numbers(n); // use vector for flexibility
    long long sum = 0;
    for (long long i = 0; i < n; i++) {
      cin >> numbers[i]; // read array elements
      sum += numbers[i]; // calculate sum
    }

    sort(numbers.begin(), numbers.end()); // sort the array

    long long max_val = 0;
    for (long long i = 0; i < n; i++) {
      max_val = max(max_val, numbers[i] * sum); // calculate max value
      sum -= numbers[i]; // subtract current number from sum for next iteration
    }

    cout << max_val << endl; // print max value
  }
  return 0;
}