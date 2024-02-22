#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<char> counter(1000, 0); // Initialize with a reasonable size and zero.
  int num;
  
  // Read the first set of numbers and update the counter.
  for (int i = 0; i < n; ++i) {
    cin >> num;
    if (num >= counter.size())  // If 'num' is greater than the counter size, resize the counter.
      counter.resize(num + 1, 0);
    ++counter[num];
  }
  
  cin >> n;
  int result = 0;
  
  // Read the second set of numbers and update the result.
  for (int i = 0; i < n; ++i) {
    cin >> num;
    if (num < counter.size())  // Only update the result if 'num' is within the counter size.
      result += counter[num];
  }
  
  cout << result << '\n';
  
  return 0;
}