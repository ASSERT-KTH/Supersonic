#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 1000001;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, i;
  while (cin >> n, n) {
    long long m[MAX_N] = {0}; // Using an array instead of a map
    int count = 0;
    long long p, q;
    while (n--) {
      cin >> i >> p >> q;
      if (m[i] == 0)
        count++; // Count the number of unique i values
      m[i] += p * q; // Update the array only when necessary
    }
    bool found = false;
    for (int i = 0; i < MAX_N; i++) {
      if (m[i] >= 1000000) {
        found = true;
        cout << i << endl;
      }
    }
    if (!found)
      cout << "NA" << endl;
  }
}