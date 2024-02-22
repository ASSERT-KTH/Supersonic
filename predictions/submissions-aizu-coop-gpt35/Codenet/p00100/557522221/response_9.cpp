#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  int n, i;
  while (cin >> n, n) {
    unordered_map<int, long long> m; // Use unordered_map instead of map for faster insertion and lookup
    vector<int> vec;
    vec.reserve(n); // Preallocate memory for the vector
    long long p, q;
    bool found = false; // Use a flag variable instead of a counter
    for (int j = 0; j < n; j++) {
      cin >> i >> p >> q;
      if (!m[i])
        vec.push_back(i);
      m[i] += p * q;
      if (m[i] >= 1000000) { // Check if the current value is greater than or equal to 1000000
        found = true;
        cout << i << endl;
        break; // Break out of the loop as soon as a value is found
      }
    }
    if (!found)
      cout << "NA" << endl;
  }
}