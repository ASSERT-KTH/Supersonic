#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<bool> data(31, false);  // Initialize a boolean vector of size 31 with all false values
  int n;
  for (int i = 0; i < 28; i++) {
    cin >> n;
    data[n] = true;  // Set the corresponding index to true if the number exists
  }
  for (int i = 1; i <= 30; i++) {
    if (!data[i])  // If the number does not exist, print it
      cout << i << endl;
  }
}