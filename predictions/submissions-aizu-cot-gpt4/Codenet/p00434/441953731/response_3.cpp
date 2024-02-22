#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> data(31, 0);
  int n;
  for (int i = 0; i < 28; i++) {
    cin >> n;
    data[n] = 1;
  }
  for (int i = 1; i <= 30; i++) {
    if (data[i] == 0)
      cout << i << endl;
  }
}