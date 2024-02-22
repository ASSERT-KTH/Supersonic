#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<bool> data(30, false);
  int n;
  for (int i = 0; i < 28; i++) {
    cin >> n;
    data[n - 1] = true; // Mark as present
  }
  for (int i = 1; i <= 30; i++) {
    if (!data[i - 1]) // Check if present
      cout << i << endl;
  }
}